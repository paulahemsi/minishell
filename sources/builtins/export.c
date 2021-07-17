/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 20:23:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/17 11:06:40 by phemsi-a         ###   ########.fr       */
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

int	export(void)
{
	char	**ordered_env;
	int		i;

	i = -1;
	ordered_env = hashmap_to_env(g_minishell.env);
	quick_sort_2d_array(ordered_env, 0, get_2d_array_len(ordered_env));
	join_2d_array("declare -x ", ordered_env);
	print_2d_array_fd(ordered_env , 1);
	free_2d_array(ordered_env);
	return (0);
}