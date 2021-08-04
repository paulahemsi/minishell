/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:56:45 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/04 16:39:02 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_and_expand_variable(t_var *aux, bool *has_variable)
{
	expand_variables(&aux->before);
	expand_variables(&aux->value);
	expand_variables(&aux->after);
	*has_variable = TRUE;
}

static void	split_aux_strings(t_var *aux, char *token, int i, int end_quote)
{
	aux->before = ft_substr(token, 0, i);
	aux->value = ft_substr(token, i, (end_quote + 1 - i));
	aux->after = ft_substr(token, end_quote + 1, ft_strlen(&token[end_quote]));
}

static void	remove_all_quotes(t_var *aux, char	**token_arg, int *end_quote)
{
	char	*token;

	token = *token_arg;
	remove_quotes(&aux->after, token[*end_quote]);
	remove_quotes(&aux->value, token[*end_quote]);
	remove_quotes(&aux->before, token[*end_quote]);
}

static void	define_first_quote(char *first_quote, char *token)
{
	int		i;

	i = 1;
	*first_quote = *token;
	while ((*first_quote != SINGLE_QUOTE) && (*first_quote != DOUBLE_QUOTE))
	{
		*first_quote = *(token + i);
		i++;
	}
}

void	handle_quotes(char **token_ptr, int i, int *end_quote)
{
	t_var	aux;
	char	*token;
	char	first_quote;
	bool	has_variable;

	has_variable = FALSE;
	token = *token_ptr;
	define_first_quote(&first_quote, token);
	split_aux_strings(&aux, token, i, *end_quote);
	if ((token[*end_quote] == DOUBLE_QUOTE) && (ft_strchr(token, '$')))
		check_and_expand_variable(&aux, &has_variable);
	remove_all_quotes(&aux, &token, end_quote);
	free(token);
	token = variadic_strjoin(3, aux.before, aux.value, aux.after);
	*token_ptr = token;
	define_end_quote(token, has_variable, first_quote, end_quote);
	free_var_struct(&aux);
}
