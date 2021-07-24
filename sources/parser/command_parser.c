/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:02:40 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/24 18:38:43 by phemsi-a         ###   ########.fr       */
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

static void	execute_builtin(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "echo\0")))
		ft_printf("EXECUTAR ECHO \n");
	else if (!(ft_strcmp(cmd[0], "cd\0")))
		cd(cmd[1]);
	else if (!(ft_strcmp(cmd[0], "pwd")))
		pwd();
	else if (!(ft_strcmp(cmd[0], "export")))
		export(cmd);
	else if (!(ft_strcmp(cmd[0], "unset")))
		unset(cmd[1]);
	else if (!(ft_strcmp(cmd[0], "env")))
		print_environment(g_minishell.env, STDOUT_FILENO);
	else if (!(ft_strcmp(cmd[0], "exit")))
		exit_minishell();
}

//TODO: make_redirects();
void	command_parser(t_token *token_lst, t_token *pipe)
{
	char	**cmd;

	save_std_fds();
	create_pipe(pipe);
	cmd = NULL;
	cmd = create_command_array(token_lst, pipe, cmd);
	if (is_builtin(cmd[0]))
		execute_builtin(cmd);
	else
		execute_cmd(cmd);
	free_2d_array(cmd);
	restore_std_fds();
}
