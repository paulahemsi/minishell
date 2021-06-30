/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:11:55 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/29 23:45:46 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_builtin(char *value)
{
	if (!(ft_strcmp(value, "echo\0")) || !(ft_strcmp(value, "cd\0")))
		return (1);
	if (!(ft_strcmp(value, "pwd")) || !(ft_strcmp(value, "export")))
		return (1);
	if (!(ft_strcmp(value, "unset")) || !(ft_strcmp(value, "env")))
		return (1);
	if (!(ft_strcmp(value, "exit")))
		return (1);
	return (0);
}

static int	is_operator(char *value)
{
	if (!(ft_strcmp(value, "|")) || !(ft_strcmp(value, "=")))
		return (1);
	if (!(ft_strcmp(value, ">")) || !(ft_strcmp(value, "<")))
		return (1);
	if (!(ft_strcmp(value, ">>")) || !(ft_strcmp(value, "<<")))
		return (1);
	return (0);
}

static void	define_type(char *value, int *type)
{
	if (is_builtin(value))
		*type = T_BUILTIN;
	else if (is_operator(value))
		*type = T_OPERATOR;
	else
		*type = T_LITERAL;
}

void	add_token(char *line, int start, int end, t_token **token_lst)
{
	char	*value;
	int		type;

	value = ft_substr(line, start, (end - start));
	if (value[0] == SINGLE_QUOTE)
		remove_quotes(&value, SINGLE_QUOTE);
	else
		expand_variables(&value);
	define_type(value, &type);
	tkn_add_back(token_lst, tkn_new(value, type));
}
