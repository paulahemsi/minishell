/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:13:18 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/27 21:43:54 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define TMP_FILE	"/tmp/minihell_temporary_file"

void	here_doc_input(char *eof)
{
	int		tmp_fd;
	char	*input;

	tmp_fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (tmp_fd == -1)
	{
		error_message("redirect", strerror(errno));
		g_minishell.error_status = 1;
		return ;
	}
	while (true)
	{
		input = readline("> ");
		if (ft_strcmp(input, eof))
			ft_putendl_fd(input, tmp_fd);
		else
		{
			close(tmp_fd);
			free(input);
			break ;
		}
		free(input);
	}
	tmp_fd = open(TMP_FILE, O_RDONLY);
	unlink(TMP_FILE);
	dup2(tmp_fd, IN);
	close(tmp_fd);
}

