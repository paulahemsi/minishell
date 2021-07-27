/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:07:19 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/26 20:56:32 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	interrupt_process(int signal)
{
	(void)signal;
	g_minishell.error_status = 130;
	write(1, "\n", 1);
}

static void	redisplay_prompt(int signal)
{
	(void)signal;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	quit_process(int signal)
{
	(void)signal;
	g_minishell.error_status = 130;
	ft_printf("Quit (core dumped)\n");
}

void	define_exec_signals(void)
{
	signal(SIGINT, interrupt_process);
	signal(SIGQUIT, quit_process);
}

void	define_input_signals(void)
{
	signal(SIGINT, redisplay_prompt);
	signal(SIGQUIT, SIG_IGN);
}
