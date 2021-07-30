/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:12:51 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/30 20:29:54 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "input.h"
# include "tokenizer.h"
# include "parser.h"
# include "error.h"
# include "hashmap.h"
# include "builtin.h"
# include <stdbool.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_minishell
{
	t_hashmap	*env;
	t_hashmap	*local_vars;
	int			save_fd[2];
	int			old_pipe_in;
	int			error_status;
}				t_minishell;

/*
** GLOBAL VARIABLE FOR SESSION INFORMATION:
*/

t_minishell	g_minishell;

/*
** UTILS: 
*/

void	print_2d_array_fd(char **array, int fd);
void	free_2d_array(char **ptr);

/*
** EXEC:
*/

char	*get_absolute_path(char *cmd);
void	execute(char **cmd);

#endif
