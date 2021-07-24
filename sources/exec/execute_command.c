/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:30:15 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/24 12:28:37 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(char **cmd)
{
	int		pid;
	char	**env_variables;

	pid = fork();
	if (pid == 0)
	{
		env_variables = hashmap_to_env(g_minishell.env);
		execve(cmd[0], cmd, env_variables);
		free_2d_array(env_variables);
	}
	waitpid(pid, NULL, 0);
}
