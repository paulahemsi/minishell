/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:59:12 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/29 18:28:34 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"

# define T_BUILTIN		42
# define T_OPERATOR		43
# define T_LITERAL		44

# define SINGLE_QUOTE	'\''
# define DOUBLE_QUOTE	'\"'

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
}	t_token;

void	tokenizer(char *line);
t_token	*split_tokens(char *line);
void	add_token(char *line, int start, int end, t_token **token_lst);
int		is_btw_quotes(char *line, int i, int *match_index, char c);
void	remove_quotes(char **value, char quote);
/*
** token linked list (token_lst.c)
*/
t_token	*tkn_new(char *value, int type);
void	tkn_add_back(t_token **lst, t_token *new_token);
void	tkn_lstclear(t_token **lst);
/*
** variables_expansion.c
*/
void	expand_variable(char **value);
void	check_variables_inside_string(char **value);

# endif
