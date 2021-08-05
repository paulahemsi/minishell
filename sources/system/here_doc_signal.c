/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_signal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 09:09:17 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/05 09:10:03 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	interrupt_here_document(int signal)
{
	(void)signal;
	g_minishell.error_status = 130;
	write(1, "\n", 1);
	exit(130);
}
