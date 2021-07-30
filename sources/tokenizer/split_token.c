/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 21:11:55 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/30 00:40:20 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_quotes(char **token_ptr, int i, int end_quote)
{
	char	*token;
	t_var	aux;

	token = *token_ptr;
	aux.before = ft_substr(token, 0, i);
	aux.value = ft_substr(token, i, (end_quote + 1 - i));
	aux.after = ft_substr(token, end_quote + 1, ft_strlen(&token[end_quote]));
	if (token[end_quote] == DOUBLE_QUOTE)
		expand_variables(&aux.value);
	remove_quotes(&aux.value, token[end_quote]);
	aux.temp = ft_strjoin(aux.before, aux.value);
	token = ft_strjoin(aux.temp, aux.after);
	*token_ptr = token;
	free_var_struct(&aux);
}

static void	check_quotes(char **value)
{
	int		i;
	int		end_quote;
	char	*token;

	i = 0;
	token = *value;
	while (token[i])
	{
		if (is_between_quotes(token, i, &end_quote, token[i]))
		{
			handle_quotes(&token, i, end_quote);
			i = end_quote - 1;
		}
		if (token[i])
			i++;
	}
	free(*value);
	*value = token;
}

static void	add_token(char *line, int start, int end, t_token **token_lst)
{
	char	*value;
	int		type;

	value = ft_substr(line, start, (end - start));
	if (!value)
		return ;
	if (ft_strchr(value, SINGLE_QUOTE) || ft_strchr(value, DOUBLE_QUOTE))
		check_quotes(&value);
	else if (ft_strchr(value, '$'))
		expand_variables(&value);
	define_type(token_last(*token_lst), value, &type);
	token_add_back(token_lst, token_new(value, type));
}

static int	find_end(char *line, int i, int *end)
{
	while (!(ft_isblank(line[i])) && (line[i]))
	{
		if (is_between_quotes(line, i, &i, line[i]))
		{
			i++;
			continue ;
		}
		i++;
	}
	*end = i;
	return (i);
}

int	split_token(char *line, int *i, int *tkn_end, t_token **token_lst)
{
	while (ft_isblank(line[*i]))
		*i += 1;
	if (!line[*i])
		return (0);
	add_token(line, *i, find_end(line, *i, tkn_end), token_lst);
	*i = *tkn_end;
	if (line[*i])
		*i += 1;
	return (1);
}
