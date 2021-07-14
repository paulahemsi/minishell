/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:07:19 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/14 17:16:54 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_interrupt_signal()
{
	write(1, "aqui\n", 5);
}

void	handle_quit_signal()
{
	write(1, "aqui2\n", 6);
}

void	define_signals()
{
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, handle_quit_signal);
}
