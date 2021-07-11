/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:09:54 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/11 20:10:53 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "tokenizer.h"

# define IN		0
# define OUT	1
# define READ	0
# define WRITE	1

# define TRUE	1
# define FALSE	0

typedef struct s_cmd
{
	char			**cmd;
	int				is_builtin;
	int				pipe;
	int				redirect;
	int				fd[2];
	struct s_cmd	*next;
}	t_cmd;

void	parser(t_token *token_lst);
t_cmd	*cmd_new(void);
void	cmd_add_back(t_cmd **lst, t_cmd *new_cmd);

#endif
