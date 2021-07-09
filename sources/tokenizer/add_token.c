/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:11:55 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/06 19:32:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_builtin(char *value)
{
	if (!(ft_strcmp(value, "echo\0")) || !(ft_strcmp(value, "cd\0")))
		return TRUE;
	if (!(ft_strcmp(value, "pwd")) || !(ft_strcmp(value, "export")))
		return TRUE;
	if (!(ft_strcmp(value, "unset")) || !(ft_strcmp(value, "env")))
		return TRUE;
	if (!(ft_strcmp(value, "exit")))
		return TRUE;
	return FALSE;
}

static bool	is_operator(char *value)
{
	if (!(ft_strcmp(value, "|")) || !(ft_strcmp(value, "=")))
		return TRUE;
	if (!(ft_strcmp(value, ">")) || !(ft_strcmp(value, "<")))
		return TRUE;
	if (!(ft_strcmp(value, ">>")) || !(ft_strcmp(value, "<<")))
		return TRUE;
	return FALSE;
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

static void	check_quotes(char **value)
{
	int		i;
	int		end_quote;
	char	*token;
	t_var	aux;

	i = 0;
	token = *value;
	while (token[i])
	{
		if (is_between_quotes(token, i, &end_quote, token[i]))
		{
			aux.before = ft_substr(token, 0, i);
			aux.value = ft_substr(token, i, (end_quote + 1 - i));
			aux.after = ft_substr(token, (end_quote + 1), ft_strlen(&token[end_quote]));
			if (token[end_quote] == DOUBLE_QUOTE)
				expand_variables(&aux.value);
			remove_quotes(&aux.value, token[end_quote]);
			aux.temp = ft_strjoin(aux.before, aux.value);
			token = ft_strjoin(aux.temp, aux.after);
			free_var_struct(&aux);
			i = end_quote - 1;
		}
		if (token[i])
			i++;
	}
	free(*value);
	*value = token;
}

void	add_token(char *line, int start, int end, t_token **token_lst)
{
	char	*value;
	int		type;

	value = ft_substr(line, start, (end - start));
	if (!value)
		return ;
	if (is_single_quote(value[0]))
		remove_quotes(&value, SINGLE_QUOTE);
	else if (ft_strchr(value, SINGLE_QUOTE) || ft_strchr(value, DOUBLE_QUOTE))
		check_quotes(&value);
	else if (ft_strchr(value, '$'))
		expand_variables(&value);
	define_type(value, &type);
	token_add_back(token_lst, token_new(value, type));
}
