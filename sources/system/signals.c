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
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	handle_quit_signal()
{
	ft_printf("^\\Quit\n");
	return ;
}

void	signals_when_execv()
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, handle_quit_signal);
}

void	define_signals()
{
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
}
