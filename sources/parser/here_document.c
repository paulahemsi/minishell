/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 17:13:18 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/04 21:00:01 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define TMP_FILE	"/tmp/minihell_temporary_file"

static int	create_temporary_file(void)
{
	int	fd;

	fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		error_message("redirect", strerror(errno), 1);
	return (fd);
}

static	void	get_and_write_input(int tmp_fd, char *eof)
{
	char	*input;

	while (true)
	{
		input = readline("> ");
		if (!input)
		{
			error_message("warning",
				"here-document delimited by end-of-file", 0);
			close(tmp_fd);
			break ;
		}
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
}

static void	make_tmp_file_input(void)
{
	int		tmp_fd;

	tmp_fd = open(TMP_FILE, O_RDONLY);
	unlink(TMP_FILE);
	dup2(tmp_fd, IN);
	close(tmp_fd);
}

void	here_doc_input(char *eof, int *save_fd)
{
	int		tmp_fd;
	int		save_fd_out;

	tmp_fd = create_temporary_file();
	if (tmp_fd == -1)
		return ;
	save_fd_out = dup(OUT);
	dup2(save_fd[OUT], STDOUT_FILENO);
	get_and_write_input(tmp_fd, eof);
	make_tmp_file_input();
	dup2(save_fd_out, STDOUT_FILENO);
	close(save_fd_out);
}
