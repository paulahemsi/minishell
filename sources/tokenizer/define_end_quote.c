/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_end_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:38:38 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/04 18:08:26 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	define_end_quote(char *token, bool has_variable,
			char first_quote, int *end_quote)
{
	char	*quote;

	quote = NULL;
	quote = ft_strchr(token, DOUBLE_QUOTE);
	if (!quote && !has_variable)
		quote = ft_strchr(token, SINGLE_QUOTE);
	else if (quote && first_quote != SINGLE_QUOTE)
	{
		*quote = '\0';
		*end_quote = ft_strlen(token);
		*quote = DOUBLE_QUOTE;
	}
	else if (!quote || first_quote == SINGLE_QUOTE)
		*end_quote = ft_strlen(token);
	else
	{
		*quote = '\0';
		*end_quote = ft_strlen(token);
		*quote = SINGLE_QUOTE;
	}
}
