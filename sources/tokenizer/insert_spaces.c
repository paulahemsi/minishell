/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:11:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/31 12:45:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_operator_size(char *operator_pointer)
{
	if (*operator_pointer == *(operator_pointer + 1))
		return (2);
	return (1);
}

static void	free_aux_strings(char **left, char **operator, char **right)
{
	free(*left);
	free(*operator);
	free(*right);
}

static char	*create_new_line(char *line, char *operator_pointer,
		int operator_size, int off_set)
{
	char	*left;
	char	*operator;
	char	*right;
	char	*new_line;

	left = ft_substr(line, 0, off_set);
	operator = ft_substr(operator_pointer, 0, operator_size);
	right = ft_strdup(operator_pointer + operator_size);
	new_line = variadic_strjoin(5, left, " ", operator, " ", right);
	free_aux_strings(&left, &operator, &right);
	return (new_line);
}

char	*insert_spaces(char **line, char *operator_pointer, char *line_init)
{
	char	*new_line;
	int		operator_size;
	int		off_set;

	if (operator_pointer != line_init)
		if (*(operator_pointer - 1) == '>' || *(operator_pointer - 1) == '<')
			return (operator_pointer++);
	operator_size = get_operator_size(operator_pointer);
	off_set = operator_pointer - *line;
	new_line = create_new_line(*line, operator_pointer, operator_size, off_set);
	free(*line);
	*line = new_line;
	return (new_line + off_set + operator_size + 1);
}
