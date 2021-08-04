/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:40:48 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/04 19:55:42 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redirect_output(char *file, int flags)
{
	int	fd_file;

	fd_file = open(file, flags, 0777);
	if (fd_file == -1)
		error_message("redirect", strerror(errno), 1);
	else
	{
		dup2(fd_file, OUT);
		close(fd_file);
	}
}

static void	redirect_input(char *file, int flags)
{
	int	fd_file;

	fd_file = open(file, flags);
	if (fd_file == -1)
		error_message("redirect", strerror(errno), 1);
	else
	{
		dup2(fd_file, IN);
		close(fd_file);
	}
}

static void	make_redirect(char *redirect, char *file, int *save_fd)
{
	if (!ft_strcmp(redirect, ">"))
		redirect_output(file, O_WRONLY | O_CREAT | O_TRUNC);
	else if (!ft_strcmp(redirect, "<"))
		redirect_input(file, O_RDONLY | O_CREAT);
	else if (!ft_strcmp(redirect, ">>"))
		redirect_output(file, O_WRONLY | O_CREAT | O_APPEND);
	else if (!ft_strcmp(redirect, "<<"))
		here_doc_input(file, save_fd);
}

void	check_redirects(t_token *current, t_token *end, int *save_fd)
{
	while (current != end)
	{
		if (!current->next)
			break ;
		if (current->type == T_REDIRECT && current->next->type == T_FILE)
		{
			make_redirect(current->value, current->next->value, save_fd);
			current = current->next;
		}
		current = current->next;
	}
}
