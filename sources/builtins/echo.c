/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:59:47 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/01 11:36:41 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **cmd)
{
	bool	n_flag;
	int		i;

	i = 1;
	n_flag = false;
	if (cmd[1] && ft_strcmp(cmd[1], "-n") == 0)
	{
		n_flag = true;
		i = 2;
	}
	while (cmd && cmd[i])
	{
		ft_printf("%s ", cmd[i]);
		i++;
	}
	if (n_flag == false)
		ft_printf("\n");
	g_minishell.error_status = 0;
}
