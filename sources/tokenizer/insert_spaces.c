/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:11:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/28 15:12:18 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_between_blanks(char *line)
{
	if ((ft_isblank(*(line - 1))) && (ft_isblank(*(line + 1))))
		return (TRUE);
	return (FALSE);
}

bool	no_blanks_around_operator(char *line)
{
	if ((*line == '|') && !(is_between_blanks(line)))
		return (TRUE);
	if (*line == '>' && *(line + 1) == '>')
		if (!ft_isblank(*(line - 1)) || !ft_isblank(*(line + 2)))
			return (TRUE);
	if ((*line == '>') && !(is_between_blanks(line)))
		if (*(line + 1) != '>')
			return (TRUE);
	if (*line == '<' && *(line + 1) == '<')
		if (!ft_isblank(*(line - 1)) || !ft_isblank(*(line + 2)))
			return (TRUE);
	if ((*line == '<') && !(is_between_blanks(line)))
		if (*(line + 1) != '<')
			return (TRUE);
	return (FALSE);
}

static int	get_operator_size(char *operator_pointer)
{
	if (*operator_pointer == *(operator_pointer + 1))
		return (2);
	return (1);
}

static char	*create_new_line(char *line, char *operator_pointer,
		int operator_size, int off_set)
{
	char	*left;
	char	*operator;
	char	*rigth;
	char	*new_line;

	left = ft_substr(line, 0, off_set);
	operator = ft_substr(operator_pointer, 0, operator_size);
	rigth = ft_strdup(operator_pointer + operator_size);
	new_line = variadic_strjoin(5, left, " ", operator, " ", rigth);
	free(left);
	free(operator);
	free(rigth);
	return (new_line);
}

char	*insert_spaces(char **line, char *operator_pointer)
{
	char	*new_line;
	int		operator_size;
	int		off_set;

	if (*(operator_pointer - 1) == '>' || *(operator_pointer - 1) == '<')
		return (operator_pointer++);
	operator_size = get_operator_size(operator_pointer);
	off_set = operator_pointer - *line;
	new_line = create_new_line(*line, operator_pointer, operator_size, off_set);
	free(*line);
	*line = new_line;
	return (new_line + off_set + operator_size + 1);
}
