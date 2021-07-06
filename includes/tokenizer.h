/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 14:59:12 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/06 19:15:16 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"
# include <stdbool.h>

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

typedef struct s_var
{
	char	*before;
	char	*after;
	char	*value;
	char	*pointer;
	char	*temp;
}	t_var;

t_token	*split_tokens(char *line);
void	tokenizer(char *line, t_token **token_lst);
void	add_token(char *line, int start, int end, t_token **token_lst);
/*
** quotes.c
*/
bool	is_single_quote(char c);
bool	is_between_quotes(char *line, int i, int *match_index, char c);
void	remove_quotes(char **value, char quote);
/*
** token linked list (token_lst.c)
*/
void	token_list_clear(t_token **lst);
t_token	*token_new(char *value, int type);
void	token_add_back(t_token **lst, t_token *new_token);
/*
** variables_expansion.c
*/
void	expand(char **value);
void	expand_variables(char **value);
void	free_var_struct(t_var *var);

# endif
