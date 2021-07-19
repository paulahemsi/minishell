/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:32:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/18 21:22:51 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char *key)
{
	if (hashmap_search(g_minishell.env, key))
		hashmap_delete(g_minishell.env, key);
}
