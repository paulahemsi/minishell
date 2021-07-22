/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:02:40 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/22 20:44:07 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void	execute_cmd(char **cmd)
{
	int	pid;
	pid = fork();
	if (pid == 0)
		execve(cmd[0], cmd, hashmap_to_env(g_minishell.env));
	waitpid(pid, NULL, 0);
}

void	add_path_to_cmd_name(char **cmd)
{
	char	*cmd_name;
	
	cmd_name = get_absolute_path(cmd[0]);
	free(cmd[0]);
	cmd[0] = cmd_name;
}


int save_fd[2];

void save_std_fds()
{
	save_fd[IN] = dup(STDIN_FILENO);
	save_fd[OUT] = dup(STDIN_FILENO);
}

void restore_std_fds()
{
	dup2(save_fd[IN], STDIN_FILENO);
	close(save_fd[IN]);
	dup2(save_fd[OUT], STDIN_FILENO);
	close(save_fd[OUT]);
}


int old_pipe[2];

void create_pipe(t_token *pipe_token)
{
	int new_pipe[2];

	if (!pipe_token)
		return ;
	dup2(STDIN_FILENO, old_pipe[IN]);
	close(old_pipe[IN]);
	if (*pipe_token->value == '|')
	{
		pipe(new_pipe);
		dup2(STDOUT_FILENO, new_pipe[OUT]);
		close(new_pipe[OUT]);
		old_pipe[IN] = dup(new_pipe[IN]);
		close(new_pipe[IN]);
	}
}

void	command_parser(t_token *token_lst, t_token *pipe)
{
	char	**cmd;

	save_std_fds();
	create_pipe(pipe);
	//make_redirects();
	cmd = NULL;
	cmd = create_command_array(token_lst, pipe, cmd);
	
	add_path_to_cmd_name(cmd);
	execute_cmd(cmd);
	free_2d_array(cmd);	
	restore_std_fds();
}

void	pipe_checker(t_token *token_lst)
{
	old_pipe[IN] = 0;
	if (token_lst->next)
		command_parser(token_lst, token_lst->next->next);
	else
		command_parser(token_lst, NULL);
}
