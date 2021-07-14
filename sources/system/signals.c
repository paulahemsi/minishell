/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:07:19 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/14 19:03:32 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_interrupt_signal()
{
	char	*prompt;

	prompt = create_prompt();
	ft_printf("\n%s", prompt);
	free(prompt);
}

void	handle_quit_signal()
{
	return ;
}

void	define_signals()
{
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, handle_quit_signal);
}
