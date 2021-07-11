/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:22:12 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/11 20:09:48 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_message(char *input, char *error_message)
{
	ft_putstr_fd(BOLD_YELLOW, 1);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(YELLOW, 1);
	ft_putstr_fd(input, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error_message, 2);
	ft_putstr_fd(RESET_COLOR, 1);
}
