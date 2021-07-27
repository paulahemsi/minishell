/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 02:59:47 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/27 01:46:09 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **cmd)
{
	bool	n_flag;
	int		i;

	i = 1;
	n_flag = 0;
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
}
