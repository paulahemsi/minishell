/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 20:23:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/17 14:31:55 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_2d_array_len(char **array)
{
	int i;

	i = 0;
	while (array[i + 1])
		i++ ;
	return (i);
}

static void	join_2d_array(char *string_to_join, char **array)
{
	int		i;
	char	*temp;

	i = 0;
	while (array[i])
	{
		temp = ft_strjoin(string_to_join, array[i]);
		free(array[i]);
		array[i] = temp;
		i++;
	}
}

static int	print_ordered_env(int fd)
{
	char	**ordered_env;

	ordered_env = hashmap_to_env_with_quotes(g_minishell.env);
	quick_sort_2d_array(ordered_env, 0, get_2d_array_len(ordered_env));
	join_2d_array("declare -x ", ordered_env);
	print_2d_array_fd(ordered_env , fd);
	free_2d_array(ordered_env);
	return (0);
}

static int	export_variable(char **cmd, int index)
{
	char	*value;

	if (!cmd[index])
		return (0);
	value = hashmap_search(g_minishell.local_vars, cmd[index]);
	if (!value)
		value = ft_strdup("\0");
	hashmap_insert(cmd[index], value, g_minishell.env);
	hashmap_delete(g_minishell.local_vars, cmd[index]);
	free(value);
	return (export_variable(cmd, index + 1));
}

int	export(char **cmd, int fd)
{
	if (cmd[1])
		return (export_variable(cmd, 1));
	else
		return (print_ordered_env(fd));
}
