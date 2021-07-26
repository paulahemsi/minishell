/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:30:15 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/25 19:54:58 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_path_to_cmd_name(char **cmd)
{
	char	*cmd_name;

	cmd_name = get_absolute_path(cmd[0]);
	if (!cmd_name)
	{
		error_message(cmd[0], NOT_FOUND);
		return (0);
	}
	free(cmd[0]);
	cmd[0] = cmd_name;
	return (1);
}

void	execute_cmd(char **cmd)
{
	int		pid;
	char	**env_variables;

	if (!add_path_to_cmd_name(cmd))
		return ;
	pid = fork();
	define_exec_signals();
	if (pid == 0)
	{
		env_variables = hashmap_to_env(g_minishell.env);
		execve(cmd[0], cmd, env_variables);
		free_2d_array(env_variables);
	}
	waitpid(pid, NULL, 0);
}
