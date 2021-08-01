/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:58:18 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/31 17:48:05 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_minishell(void)
{
	hashmap_free_table(g_minishell.env);
	hashmap_free_table(g_minishell.local_vars);
	exit(g_minishell.error_status);
}
