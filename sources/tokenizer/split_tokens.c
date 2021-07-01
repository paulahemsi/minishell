/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:34:41 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/01 18:17:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	needs_expansion(char quote)
{
	if (quote == SINGLE_QUOTE)
		return (0);
	return (1);
}

static int	find_end(char *line, int i, int *end)
{
	while ((line[i] != ' ') && (line[i]))
		i++;
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
		while (line[i] == ' ')
			i++;
		if (is_between_quotes(line, i, &token_end, line[i])
			 && needs_expansion(line[i]))
			add_token(line, i + 1, token_end, &token_lst);
		else if (line[i] == SINGLE_QUOTE)
			add_token(line, i, token_end, &token_lst);
		else
			add_token(line, i, find_end(line, i, &token_end), &token_lst);
		i = token_end + 1;
	}
	return (token_lst);
}
