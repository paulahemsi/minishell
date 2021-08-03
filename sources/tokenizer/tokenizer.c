/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:01:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/03 13:11:29 by phemsi-a         ###   ########.fr       */
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
	if (!(*line))
		return (FALSE);
	if (*line == '$')
		line++;
	while (ft_isblank(*line))
		line++;
	if (*line)
		return (FALSE);
	error_message("$", NOT_FOUND, 127);
	return (TRUE);
}

static bool	no_need_to_tokenization(char *line)
{
	check_eof(line);
	if (line[0] == '\0')
		return (TRUE);
	if (is_single_dollar_sign(line))
		return (TRUE);
	return (FALSE);
}

void	tokenizer(char **line, t_token **token_lst)
{
	int		i;
	int		token_end;

	i = 0;
	if (no_need_to_tokenization(*line))
		return ;
	check_and_insert_spaces(line);
	token_end = i;
	while ((*line)[i])
		if (!split_token(*line, &i, &token_end, token_lst))
			break ;
}
