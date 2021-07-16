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

static void	handle_interrupt_signal(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	handle_quit_signal(int signal)
{
	(void)signal;
	ft_printf("Quit\n");
}

void	define_exec_signals_handler(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, handle_quit_signal);
}

void	define_input_signals_handler(void)
{
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
}
