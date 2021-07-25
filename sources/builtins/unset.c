/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:32:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/25 13:44:14 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		if (hashmap_search(g_minishell.env, cmd[i]))
			hashmap_delete(g_minishell.env, cmd[i]);
		else if (hashmap_search(g_minishell.local_vars, cmd[i]))
			hashmap_delete(g_minishell.local_vars, cmd[i]);
		i++;
	}
}
