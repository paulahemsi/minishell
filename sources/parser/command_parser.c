/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:02:40 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/30 16:44:24 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	save_std_fds(void)
{
	g_minishell.save_fd[IN] = dup(STDIN_FILENO);
	g_minishell.save_fd[OUT] = dup(STDIN_FILENO);
}

static void	restore_std_fds(void)
{
	dup2(g_minishell.save_fd[IN], STDIN_FILENO);
	close(g_minishell.save_fd[IN]);
	dup2(g_minishell.save_fd[OUT], STDOUT_FILENO);
	close(g_minishell.save_fd[OUT]);
}

static void	create_pipe(t_token *pipe_token)
{
	int	new_pipe[2];

	dup2(g_minishell.old_pipe_in, STDIN_FILENO);
	if (g_minishell.old_pipe_in != 0)
		close(g_minishell.old_pipe_in);
	if (!pipe_token)
		return ;
	pipe(new_pipe);
	dup2(new_pipe[OUT], STDOUT_FILENO);
	close(new_pipe[OUT]);
	g_minishell.old_pipe_in = dup(new_pipe[IN]);
	close(new_pipe[IN]);
}

static bool	check_filename_after_redirect(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		if (token->type == T_REDIRECT)
			if (!next || next->type != T_FILE)
				return (FALSE);
		token = next;
	}
	return (TRUE);
}

void	command_parser(t_token *token_lst, t_token *pipe)
{
	char	**cmd;

	if (!check_filename_after_redirect(token_lst))
	{
		error_message("redirect", SYNTAX_ERROR);
		g_minishell.error_status = 2;
		return ;
	}
	save_std_fds();
	create_pipe(pipe);
	check_redirects(token_lst, pipe);
	cmd = create_command_array(token_lst, pipe);
	execute(cmd);
	free_2d_array(cmd);
	restore_std_fds();
}
