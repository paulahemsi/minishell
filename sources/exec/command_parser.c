/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 18:02:40 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/21 20:16:56 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **create_array(t_token *token_lst)
{
	char **cmd;

	cmd = ft_calloc(3, sizeof(char *));
	cmd[0] = ft_strdup(token_lst->value);
	cmd[1] = ft_strdup(token_lst->next->value);
	cmd[2] = NULL;
	return (cmd);
}

void	command_parser(t_token *token_lst, t_token *pipe)
{
	char	**cmd;
	char	*cmd_name;

	(void)token_lst;
	(void)pipe;
	//create_pipe();
	//make_redirects();
	cmd = create_array(token_lst);
	ft_printf("%s\n", cmd[0]);
	cmd_name = get_absolute_path(cmd[0]);
	ft_printf("%s\n", cmd_name);
	free(cmd[0]);
	cmd[0] = cmd_name;
	free_2d_array(cmd);
	//concatena path
	//executa
}

void	pipe_checker(t_token *token_lst)
{
	command_parser(token_lst, token_lst->next->next);
}
