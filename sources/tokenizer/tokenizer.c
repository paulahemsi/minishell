/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:01:46 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/27 19:50:13 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//*DEBUGGING FUNC
static void	print_token_lst(t_token *token_lst)
{
	while (token_lst->next != NULL)
	{
		ft_printf("type: %i value: %s\n", token_lst->type, token_lst->value);
		token_lst = token_lst->next;
	}
	ft_printf("type: %i value: %s\n", token_lst->type, token_lst->value);
}

void	tokenizer(char *line)
{
	t_token	*token_lst;
	token_lst = split_tokens(line);
	print_token_lst(token_lst); //*DEBUGGING LINE
	//parser(token_lst);
}
