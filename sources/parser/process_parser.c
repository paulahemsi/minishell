/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:19:31 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/23 11:37:29 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipe_checker(t_token *head)
{
	t_token	*current;

	current = head;
	while (current)
	{
		if (current->type == T_PIPE)
		{
			command_parser(head, current);
			head = current->next;
			pipe_checker(head);
			break ;
		}
		current = current->next;
	}
	if (!current)
		command_parser(head, current);
}

static void	set_first_input_fd(void)
{
	g_minishell.old_pipe_in = 0;
}

static void	close_last_input_fd(void)
{
	if (g_minishell.old_pipe_in != 0)
		close(g_minishell.old_pipe_in);
}

void	parse_and_execute(t_token *token_lst)
{
	set_first_input_fd();
	pipe_checker(token_lst);
	close_last_input_fd();
}
