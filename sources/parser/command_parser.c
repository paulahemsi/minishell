/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:02:40 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/23 11:35:10 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_path_to_cmd_name(char **cmd)
{
	char	*cmd_name;

	cmd_name = get_absolute_path(cmd[0]);
	free(cmd[0]);
	cmd[0] = cmd_name;
}

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

void	command_parser(t_token *token_lst, t_token *pipe)
{
	char	**cmd;

	save_std_fds();
	create_pipe(pipe);
	//TODO: make_redirects();
	cmd = NULL;
	cmd = create_command_array(token_lst, pipe, cmd);
	//TODO: executar buitin
	add_path_to_cmd_name(cmd);
	execute_cmd(cmd);
	free_2d_array(cmd);
	restore_std_fds();
}
