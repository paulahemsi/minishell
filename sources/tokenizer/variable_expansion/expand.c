/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:56:39 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/30 17:12:50 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_double_quotes(char **temp, bool *has_quote, char **key)
{
	if (ft_strchr(*temp, DOUBLE_QUOTE))
	{
		*key = ft_strtrim(*temp, "\"");
		*has_quote = TRUE;
	}
	else
		*key = ft_strdup(*temp);
}

static void	define_value(char **value, char *key)
{
	*value = ft_strdup(hashmap_search(g_minishell.env, key));
	if (!*value)
		*value = ft_strdup(hashmap_search(g_minishell.local_vars, key));
	if (!*value)
		*value = ft_strdup("");
}

static void	restore_quote(bool has_quote, char **value, char **temp)
{
	if (has_quote)
	{
		*temp = ft_strjoin(*value, "\"");
		free(*value);
		*value = ft_strdup(*temp);
		free(*temp);
	}
}

void	expand(char **variable)
{
	char	*value;
	char	*key;
	char	*temp;
	bool	has_quote;

	has_quote = FALSE;
	temp = *variable;
	temp++;
	check_double_quotes(&temp, &has_quote, &key);
	define_value(&value, key);
	free(*variable);
	free(key);
	restore_quote(has_quote, &value, &temp);
	*variable = value;
}
