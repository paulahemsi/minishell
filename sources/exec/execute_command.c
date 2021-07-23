/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 11:30:15 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/23 11:34:57 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(char **cmd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		execve(cmd[0], cmd, hashmap_to_env(g_minishell.env));
	waitpid(pid, NULL, 0);
}
