/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:01:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/22 00:09:28 by phemsi-a         ###   ########.fr       */
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

static int	split_token(char *line, int *i, int *token_end, t_token **token_lst)
{
	while (ft_isblank(line[*i]))
		*i += 1;
	if (!line[*i])
		return (0);
	add_token(line, *i, find_end(line, *i, token_end), token_lst);
	*i = *token_end;
	if (line[*i])
		*i += 1;
	return (1);
}

// static bool	is_redirect_char(char c)
// {
// 	if ((c == '>') || (c == '<'))
// 		return (TRUE);
// 	return (FALSE);
// }

// static void check_and_add_spaces(char **line)
// {
// 	int		i;
// 	t_var	aux;
// 	char	*line_to_check;

// 	i = 0;
// 	line_to_check = *line;
// 	ft_memset(&aux, 0, sizeof(aux));
// 	while (line_to_check[i])
// 	{
// 		if (is_redirect_char(line_to_check[i]))
// 		{
// 			i++;
// 			if (is_redirect_char(line_to_check[i]))
// 				i++;
// 			if (line_to_check[i] != ' ')
// 			{
// 				aux.before = ft_substr(line_to_check, 0, i - 1);
// 				aux.value = ft_strdup(" ");
// 				aux.after = ft_strdup(&line_to_check[i]);
// 				free(line_to_check);
// 				line_to_check = variadic_strjoin(3, aux.before, aux.value, aux.after);
// 				free_var_struct(&aux);
// 			}
// 		}
// 		i++;
// 	}
// 	line = &line_to_check;
// }

void	tokenizer(char *line, t_token **token_lst)
{
	int		i;
	int		token_end;

	i = 0;
	token_end = i;
	//?check_and_add_spaces(&line);
	while (line[i])
		if (!split_token(line, &i, &token_end, token_lst))
			break ;
	print_token_lst(*token_lst);
}
