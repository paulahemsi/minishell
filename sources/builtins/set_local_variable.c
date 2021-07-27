/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_local_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:40:01 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/27 01:36:23 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_variable(t_hashmap *table, char *key, char *value)
{
	hashmap_delete(table, key);
	hashmap_insert(key, value, table);
}

static t_hashmap	*define_hashtable(char **variable)
{
	t_hashmap	*table;

	if (hashmap_search(g_minishell.env, variable[KEY]))
		table = g_minishell.env;
	else if (hashmap_search(g_minishell.local_vars, variable[KEY]))
		table = g_minishell.local_vars;
	else
		table = NULL;
	return (table);
}

static void	define_variable(char **cmd, int index)
{
	char		**variable;
	t_hashmap	*table;

	variable = split_in_two(cmd[index], '=');
	table = define_hashtable(variable);
	if (table)
		update_variable(table, variable[KEY], variable[VALUE]);
	else
		hashmap_insert(variable[KEY], variable[VALUE], g_minishell.local_vars);
	free_2d_array(variable);
}

static int	set_variables(char **cmd, int *index)
{
	if ((!cmd[*index]) || (!(ft_strchr(cmd[*index], '='))))
		return (0);
	define_variable(cmd, *index);
	*index += 1;
	return (set_variables(cmd, index));
}

int	set_local_variable(char **cmd, int *i)
{
	set_variables(cmd, i);
	return (1);
}
