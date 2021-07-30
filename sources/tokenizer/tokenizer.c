/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:01:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/30 00:40:03 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_eof(char *line)
{
	if (line)
		return ;
	ft_printf("exit\n");
	exit_minishell();
}

static bool	is_single_dollar_sign(char *line)
{
	while (ft_isblank(*line))
		line++;
	if (*line == '$')
		line++;
	while (ft_isblank(*line))
		line++;
	if (*line)
		return (FALSE);
	error_message("$", NOT_FOUND);
	g_minishell.error_status = 127;
	return (TRUE);
}

static void	check_and_insert_spaces(char **line)
{
	char	*current;
	char	*line_init;

	current = *line;
	line_init = *line;
	while (current && *current)
	{
		if (no_blanks_around_operator(current, line_init))
			current = insert_spaces(line, current, line_init);
		current++;
	}
}

void	tokenizer(char **line, t_token **token_lst)
{
	int		i;
	int		token_end;

	check_eof(*line);
	if (is_single_dollar_sign(*line))
		return ;
	check_and_insert_spaces(line);
	i = 0;
	token_end = i;
	while ((*line)[i])
		if (!split_token(*line, &i, &token_end, token_lst))
			break ;
}
