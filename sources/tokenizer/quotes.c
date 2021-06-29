/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:11:12 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/29 11:34:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	has_a_match(char *line, int i, int *match_index, char c)
{
	while (line[i++] != '\0')
	{
		if (line[i] == c)
		{
			*match_index = i;
			return (1);
		}
	}
	return (0);
}

static int is_quote(char c)
{
	if (c == SINGLE_QUOTE|| c == DOUBLE_QUOTE)
		return (1);
	return (0);
}

int	is_btw_quotes(char *line, int i, int *match_index, char c)
{
	if (is_quote(c) && has_a_match(line, i, match_index, c))
		return (1);
	return (0);
}

void	remove_quotes(char **value, char quote)
{
	char	*temp;

	temp = ft_strtrim(*value, &quote);
	free(*value);
	*value = temp;
}
