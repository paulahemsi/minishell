/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:22:12 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/01 11:49:32 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_message(char *input, char *error_message, int status)
{
	char	*error_output;

	error_output = variadic_strjoin(
			7,
			BOLD_YELLOW,
			"minishell: ",
			YELLOW, input,
			": ",
			error_message,
			RESET_COLOR);
	ft_putendl_fd(error_output, 2);
	g_minishell.error_status = status;
	free(error_output);
}
