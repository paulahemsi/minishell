/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 20:23:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/01 11:39:38 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_ordered_env(void)
{
	char	**ordered_env;

	ordered_env = hashmap_to_env_with_quotes(g_minishell.env);
	quick_sort_2d_array(ordered_env, 0, get_2d_array_len(ordered_env));
	join_2d_array("declare -x ", ordered_env);
	print_2d_array_fd(ordered_env, STDOUT_FILENO);
	free_2d_array(ordered_env);
	return (0);
}

static void	define_variable(char **cmd, int index)
{
	char	**variable;

	variable = split_in_two(cmd[index], '=');
	if (hashmap_search(g_minishell.env, variable[KEY]))
		hashmap_delete(g_minishell.env, variable[KEY]);
	hashmap_insert(variable[KEY], variable[VALUE], g_minishell.env);
	free_2d_array(variable);
}

static void	update_variable(char **cmd, int index)
{
	char	*value;
	bool	free_value_is_needed;

	free_value_is_needed = FALSE;
	if (hashmap_search(g_minishell.env, cmd[index]))
		return ;
	value = hashmap_search(g_minishell.local_vars, cmd[index]);
	if (!value)
	{
		value = ft_strdup("");
		free_value_is_needed = TRUE;
	}
	if (hashmap_search(g_minishell.env, cmd[index]))
		hashmap_delete(g_minishell.env, cmd[index]);
	hashmap_insert(cmd[index], value, g_minishell.env);
	hashmap_delete(g_minishell.local_vars, cmd[index]);
	if (free_value_is_needed)
		free(value);
}

static int	export_variable(char **cmd, int index)
{
	if (!cmd[index])
		return (0);
	if (ft_strchr(cmd[index], '='))
		define_variable(cmd, index);
	else
		update_variable(cmd, index);
	return (export_variable(cmd, index + 1));
}

int	export(char **cmd)
{
	g_minishell.error_status = 0;
	if (cmd[1])
		return (export_variable(cmd, 1));
	else
		return (print_ordered_env());
}
