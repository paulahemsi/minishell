/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:02:40 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/21 23:21:28 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void	execute_cmd(char **cmd)
{
	int	pid;
	if ((pid = fork()) == 0)
		execve(cmd[0], cmd, hashmap_to_env(g_minishell.env));
	waitpid(pid, NULL, 0);
}

void	command_parser(t_token *token_lst, t_token *pipe)
{
	char	**cmd;
	char	*cmd_name;

	//create_pipe();
	//make_redirects();
	cmd = NULL;
	cmd = create_command_array(token_lst, pipe, cmd);
	ft_printf("%s\n", cmd[0]);
	
	//concatena path
	cmd_name = get_absolute_path(cmd[0]);
	ft_printf("%s\n", cmd_name);
	free(cmd[0]);
	cmd[0] = cmd_name;
	execute_cmd(cmd);
	free_2d_array(cmd);	
}

void	pipe_checker(t_token *token_lst)
{
	if (token_lst->next)
		command_parser(token_lst, token_lst->next->next);
	else
		command_parser(token_lst, NULL);
}
