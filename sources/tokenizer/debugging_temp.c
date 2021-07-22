/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 23:39:22 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/21 23:39:38 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**DEBUGGING FUNC
*/
static char	*get_type(int type_id)
{
	if (type_id == 42)
		return (ft_strdup("T_BUILTIN"));
	if (type_id == 43)
		return (ft_strdup("T_LITERAL"));
	if (type_id == 44)
		return (ft_strdup("T_PIPE"));
	if (type_id == 45)
		return (ft_strdup("T_REDIRECT"));
	if (type_id == 46)
		return (ft_strdup("T_HERE_DOC"));
	return (NULL);
}

/*
**DEBUGGING FUNC
*/
void	print_token_lst(t_token *token_lst)
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
