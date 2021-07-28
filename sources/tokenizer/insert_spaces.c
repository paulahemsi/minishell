/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:11:19 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/28 08:56:19 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_between_blanks(char *line, int i)
{
	if ((ft_isblank(line[i - 1])) && (ft_isblank(line[i + 1])))
		return (TRUE);
	return (FALSE);
}

static bool	is_smashed_operator(char *line, int i)
{
	if ((line[i] == '|') && !(is_between_blanks(line, i)))
		return (TRUE);
	if ((line[i] == '>') && !(is_between_blanks(line, i)))
		if (line[i + 1] != '>')
			return (TRUE);
	if ((line[i] == '<') && !(is_between_blanks(line, i)))
		if (line[i + 1] != '<')
			return (TRUE);
	return (FALSE);
}

static bool	no_issues_in_string(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_smashed_operator(line, i))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static char	*insert_spaces(char *line, int *i)
{
	char	*operator;
	char	*new_line;
	char	**splited;
	char	*operator_pointer;
	int		off_set;

	off_set = 0;
	if (line[*i] == line[*i + 1])
		off_set = 1;
	operator_pointer = &line[*i];
	splited = split_in_two_by_pointer(line, operator_pointer + off_set);
	operator = ft_substr(line, *i, 1);
	new_line = variadic_strjoin(5, splited[0], " ", operator, " ", splited[1]);
	free(operator);
	free_2d_array(splited);
	if (off_set)
		*i += 1;
	*i += 1;
	return (new_line);
}

char	*check_and_insert_spaces(char **line)
{
	char	*new_line;
	char	*temp;
	int		i;

	if (no_issues_in_string(*line))
		return (*line);
	i = 0;
	new_line = *line;
	while (new_line[i])
	{
		if (is_smashed_operator(new_line, i))
		{
			temp = insert_spaces(new_line, &i);
			new_line = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
	return (new_line);
}
