/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:43:12 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/08/03 09:48:07 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replace_tild(char **new_value)
{
	*new_value = ft_strdup(hashmap_search(g_minishell.env, "HOME"));
	if (!*new_value)
		*new_value = ft_strdup("/");
}

static bool	is_only_dollar_sign(char *value)
{
	while (*value)
	{
		if (*value != '$')
			return (FALSE);
		value++;
	}
	return (TRUE);
}

static void	deal_with_multiple_dollar_sign(char **new_value, char *value)
{
	char	*total;

	total = ft_itoa(ft_strlen(value) / 2);
	*new_value = variadic_strjoin(5, GREEN,
			"Parabéns! Você encontrou um easter egg! Insira aqui ",
			total,
			" x o PID :)",
			RESET_COLOR);
	free(total);
}

bool	if_is_special_case(char *value)
{
	if (!ft_strncmp(value, "~", 2))
		return (TRUE);
	else if (!ft_strncmp(value, "$", 2))
		return (TRUE);
	else if (!ft_strncmp(value, "$$", 3))
		return (TRUE);
	else if (is_only_dollar_sign(value))
		return (TRUE);
	return (FALSE);
}

void	deal_with_special_case(char **value)
{
	char	*new_value;

	new_value = NULL;
	if (!ft_strncmp(*value, "~", 2))
		replace_tild(&new_value);
	else if (!ft_strncmp(*value, "$", 2))
		new_value = ft_strdup("$");
	else if (!ft_strncmp(*value, "$$", 3))
		new_value = variadic_strjoin(3, GREEN,
				"Parabéns! Você encontrou um easter egg! Insira aqui o PID :)",
				RESET_COLOR);
	else if (is_only_dollar_sign(*value))
		deal_with_multiple_dollar_sign(&new_value, *value);
	free(*value);
	*value = new_value;
}
