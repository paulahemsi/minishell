/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:32:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/24 19:17:24 by phemsi-a         ###   ########.fr       */
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
		i++;
	}
}
