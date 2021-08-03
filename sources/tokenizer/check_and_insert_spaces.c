/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_insert_spaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:11:51 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/03 15:01:18 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	has_a_match(char **current, char c)
{
	char	*current_char;

	current_char = *current;
	current_char++;
	while (*current_char != '\0')
	{
		if (*current_char == c)
		{
			*current = current_char;
			return (TRUE);
		}
		current_char++;
	}
	return (FALSE);
}

static bool	is_operator(char *value)
{
	if (!(ft_strncmp(value, "|", 1)))
		return (TRUE);
	if (!(ft_strncmp(value, ">>", 2)) || !(ft_strncmp(value, "<<", 2)))
		return (TRUE);
	if (!(ft_strncmp(value, ">", 1)) || !(ft_strncmp(value, "<", 1)))
		return (TRUE);
	return (FALSE);
}

static bool	is_only_operator(char *current)
{
	char	quote;
	char	operator;

	quote = *current;
	current++;
	while (ft_isblank(*current))
		current++;
	if (!is_operator(current))
		return (FALSE);
	operator = *current;
	current++;
	if (*current == operator)
		current++;
	while (ft_isblank(*current))
		current++;
	if (*current != quote)
		return (FALSE);
	return (TRUE);
}

static bool	string_between_quotes(char **current)
{
	char	*current_char;

	current_char = *current;
	if (is_only_operator(current_char))
		return (FALSE);
	if (is_quote(*current_char) && has_a_match(current, *current_char))
		return (TRUE);
	return (FALSE);
}

void	check_and_insert_spaces(char **line)
{
	char	*current;
	char	*line_init;

	current = *line;
	line_init = *line;
	while (current && *current)
	{
		if (string_between_quotes(&current))
		{
			current++;
			continue ;
		}
		if (no_blanks_around_operator(current, line_init))
			current = insert_spaces(line, current, line_init);
		current++;
	}
}
