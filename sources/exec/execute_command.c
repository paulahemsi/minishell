/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:30:15 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/30 10:50:59 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_path_to_cmd_name(char **cmd)
{
	char	*cmd_name;

	if (!cmd[0])
		return (0);
	cmd_name = get_absolute_path(cmd[0]);
	if (!cmd_name)
	{
		error_message(cmd[0], NOT_FOUND);
		g_minishell.error_status = 127;
		return (0);
	}
	free(cmd[0]);
	cmd[0] = cmd_name;
	return (1);
}

static void	execute_builtin(char **cmd)
{
	if (!(ft_strcmp(cmd[0], "echo\0")))
		echo(cmd);
	else if (!(ft_strcmp(cmd[0], "cd\0")))
		cd(cmd[1]);
	else if (!(ft_strcmp(cmd[0], "pwd")))
		pwd();
	else if (!(ft_strcmp(cmd[0], "export")))
		export(cmd);
	else if (!(ft_strcmp(cmd[0], "unset")))
		unset(cmd);
	else if (!(ft_strcmp(cmd[0], "env")))
		print_environment(g_minishell.env, STDOUT_FILENO);
	else if (!(ft_strcmp(cmd[0], "exit")))
		exit_minishell();
}

static void	execute_cmd(char **cmd)
{
	int		pid;
	int		status;
	char	**env_variables;

	if ((!cmd[0]) || (!add_path_to_cmd_name(cmd)))
		return ;
	pid = fork();
	define_exec_signals();
	if (pid == 0)
	{
		env_variables = hashmap_to_env(g_minishell.env);
		execve(cmd[0], cmd, env_variables);
		free_2d_array(env_variables);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_minishell.error_status = WEXITSTATUS(status);
}

void	execute(char **cmd)
{
	int	i;

	i = 0;
	g_minishell.error_status = 0;
	if (cmd[i])
	{
		if (ft_strchr(cmd[i], '='))
			set_local_variable(cmd, &i);
	}
	if (is_builtin(cmd[i]))
		execute_builtin(&cmd[i]);
	else
		execute_cmd(&cmd[i]);
}
