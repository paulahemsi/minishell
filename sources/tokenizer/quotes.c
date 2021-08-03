/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:11:12 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/03 13:12:40 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	has_a_match(char *line, int i, int *match_index, char c)
{
	while (line[i++] != '\0')
	{
		if (line[i] == c)
		{
			*match_index = i;
			return (TRUE);
		}
	}
	return (FALSE);
}

bool	is_quote(char c)
{
	if (c == SINGLE_QUOTE || c == DOUBLE_QUOTE)
		return (TRUE);
	return (FALSE);
}

bool	is_single_quote(char c)
{
	if (c == SINGLE_QUOTE)
		return (TRUE);
	return (FALSE);
}

bool	is_between_quotes(char *line, int i, int *match_index, char c)
{
	if (is_quote(c) && has_a_match(line, i, match_index, c))
		return (TRUE);
	return (FALSE);
}

void	remove_quotes(char **value, char quote)
{
	char	*temp;

	temp = ft_strtrim(*value, &quote);
	free(*value);
	*value = temp;
}
