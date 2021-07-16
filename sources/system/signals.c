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
	ft_printf("Quit\n");
	//TODO: exit process
}

void	define_exec_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, quit_process);
}

void	define_input_signals(void)
{
	signal(SIGINT, redisplay_prompt);
	signal(SIGQUIT, SIG_IGN);
}
