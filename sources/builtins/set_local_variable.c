/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_local_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 10:40:01 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/25 12:29:47 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_variable(t_hashmap *table, char *key, char *value)
{
	hashmap_delete(table, key);
	hashmap_insert(key, value, table);
}

static void	define_variable(char **cmd, int index)
{
	char	**variable;

	variable = ft_split(cmd[index], '=');//!caso de dois iguais não está tratado
	if (hashmap_search(g_minishell.env, variable[KEY]))
		update_variable(g_minishell.env, variable[KEY], variable[VALUE]);
	else if (hashmap_search(g_minishell.local_vars, variable[KEY]))
		update_variable(g_minishell.local_vars, variable[KEY], variable[VALUE]);
	else
		hashmap_insert(variable[KEY], variable[VALUE], g_minishell.local_vars);
	free_2d_array(variable);
}

static int	set_variables(char **cmd, int index)
{
	if (!cmd[index])
		return (0);
	define_variable(cmd, index);
	return (set_variables(cmd, index + 1));
}

static bool	is_any_missconfiguration(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!(ft_strchr(cmd[i], '=')))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	set_local_variable(char **cmd)
{
	if (is_any_missconfiguration(cmd))
		return (0);
	set_variables(cmd, 0);
	return (1);
}
