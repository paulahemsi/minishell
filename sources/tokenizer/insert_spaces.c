/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:11:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/28 12:53:05 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_between_blanks(char *line)
{
	if ((ft_isblank(*line - 1)) && (ft_isblank(*line + 1)))
		return (TRUE);
	return (FALSE);
}

static bool	no_blanks_around_operator(char *line)
{
	if ((*line == '|') && !(is_between_blanks(line)))
		return (TRUE);
	if ((*line == '>') && !(is_between_blanks(line)))
		if (*(line + 1) != '>')
			return (TRUE);
	if ((*line == '<') && !(is_between_blanks(line)))
		if (*(line + 1) != '<')
			return (TRUE);
	return (FALSE);
}

static bool	no_issues_in_string(char *line)
{
	while (line && *line)
	{
		if (no_blanks_around_operator(line))
			return (FALSE);
		line++;
	}
	return (TRUE);
}

static char	*insert_spaces(char **line, char *operator_pointer)
{
	char	*new_line;
	char	*operator;
	char	**splited;
	int		size_operator;
	int		off_set;

	off_set = 0;
	if (operator_pointer == operator_pointer + 1)
		off_set = 1;
	splited = split_in_two_by_pointer(*line, operator_pointer + off_set);
	size_operator = off_set + 1;
	operator = ft_substr(operator_pointer, 0, size_operator);
	new_line = variadic_strjoin(5, splited[0], " ", operator, " ", splited[1]);
	off_set = operator_pointer - *line;
	free(operator);
	free(*line);
	free_2d_array(splited);
	*line = new_line;
	return (new_line + off_set + size_operator + 1);
}

void	check_and_insert_spaces(char **line)
{
	char	*current;

	if (no_issues_in_string(*line))
		return ;
	current = *line;
	while (current && *current)
	{
		if (no_blanks_around_operator(current))
			current = insert_spaces(line, current);
		current++;
	}
}
