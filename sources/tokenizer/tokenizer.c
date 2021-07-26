/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:01:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/25 20:11:10 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_end(char *line, int i, int *end)
{
	while (!(ft_isblank(line[i])) && (line[i]))
	{
		if (is_between_quotes(line, i, &i, line[i]))
		{
			i++;
			continue ;
		}
		i++;
	}
	*end = i;
	return (i);
}

static int	split_token(char *line, int *i, int *tkn_end, t_token **token_lst)
{
	while (ft_isblank(line[*i]))
		*i += 1;
	if (!line[*i])
		return (0);
	add_token(line, *i, find_end(line, *i, tkn_end), token_lst);
	*i = *tkn_end;
	if (line[*i])
		*i += 1;
	return (1);
}

void	tokenizer(char *line, t_token **token_lst)
{
	int		i;
	int		token_end;

	i = 0;
	token_end = i;
	if (!line)
	{
		ft_printf("exit\n");
		exit_minishell();
	}
	while (line[i])
		if (!split_token(line, &i, &token_end, token_lst))
			break ;
}
