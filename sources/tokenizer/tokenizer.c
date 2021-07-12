/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:01:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/01 19:17:32 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//*DEBUGGING FUNC
static char	*get_type(int type_id)
{
	if (type_id == 42)
		return (ft_strdup("T_BUILTIN"));
	if (type_id == 43)
		return (ft_strdup("T_OPERATOR"));
	if (type_id == 44)
		return (ft_strdup("T_LITERAL"));
	return (NULL);
}

//*DEBUGGING FUNC
static void	print_token_lst(t_token *token_lst)
{
	char	*type;

	while (token_lst != NULL)
	{
		type = get_type(token_lst->type);
		ft_printf("type: %s value: %s\n", type, token_lst->value);
		token_lst = token_lst->next;
		ft_free_and_null((void **)&type);
	}
}

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

static t_token	*split_tokens(char *line)
{
	int		i;
	int		token_end;
	t_token	*token_lst;

	i = 0;
	token_end = i;
	token_lst = NULL;
	while (line[i])
	{
		while (ft_isblank(line[i]))
			i++;
		if (!line[i])
			break ;
		add_token(line, i, find_end(line, i, &token_end), &token_lst);
		i = token_end;
		if (line[i])
			i++;
	}
	return (token_lst);
}

void	tokenizer(char *line, t_token **token_lst)
{
	*token_lst = split_tokens(line);
	print_token_lst(*token_lst);//*DEBUGGING LINE
}
