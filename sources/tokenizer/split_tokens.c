/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:34:41 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/04 13:54:22 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	needs_expansion(char *line, int i, int *token_end, char quote)
{
	if ((is_between_quotes(line, i, token_end, quote)))
		if (!(is_single_quote(quote)))
			return (1);
	return (0);
}

static int	find_end(char *line, int i, int *end)
{
	while (!(ft_isblank(line[i])) && (line[i]))
	{
		if (is_between_quotes(line, i, &i, line[i]))
			continue ;
		i++;
	}
	*end = i;
	return (i);
}

t_token	*split_tokens(char *line)
{
	int		i;
	int		token_end;
	t_token	*token_lst;

	i = 0;
	token_lst = NULL;
	while (line[i])
	{
		while (ft_isblank(line[i]))
			i++;
		if (!line[i])
			break ;
		if (needs_expansion(line, i, &token_end, line[i]))
			add_token(line, i + 1, token_end, &token_lst);
		else if (is_single_quote(line[i]))
			add_token(line, i, token_end, &token_lst);
		else
			add_token(line, i, find_end(line, i, &token_end), &token_lst);
		i = token_end;
		if (line[i])
			i++;
	}
	return (token_lst);
}
