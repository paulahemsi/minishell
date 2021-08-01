/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:25:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/31 18:38:37 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_exit_status_variable(char **value)
{
	if (ft_strcmp(*value, "$?") == 0)
	{
		free(*value);
		*value = ft_itoa(g_minishell.error_status);
		return (TRUE);
	}
	return (FALSE);
}

static void	deal_with_string_slices(t_var *var, char **value, int *i)
{
	var->before = ft_substr(*value, 0, *i);
	var->value = ft_substr(*value, *i, get_var_size(var->pointer, i));
	if (ft_strchr(var->value, SINGLE_QUOTE))
		handle_var_single_quote(var, value, *i);
	else
		var->after = ft_substr(*value, *i, (ft_strlen(*value) - *i));
	expand(&var->value);
}

static bool	has_dollar_sign(char **value, int *i, t_var *var)
{
	if (!(*value) || is_exit_status_variable(value))
		return (FALSE);
	var->pointer = search_var(*value, i);
	if (!(var->pointer))
		return (FALSE);
	return (TRUE);
}

static bool	only_dollar_sign_between_quotes(char **value)
{
	if (!ft_strcmp(*value, "\"$\""))
	{
		free(*value);
		*value = ft_strdup("$");
		return (TRUE);
	}
	return (FALSE);
}

void	expand_variables(char **value)
{
	t_var	var;
	char	*new_str;
	int		i;

	i = 0;
	if (!has_dollar_sign(value, &i, &var)
		|| only_dollar_sign_between_quotes(value))
		return ;
	deal_with_string_slices(&var, value, &i);
	new_str = variadic_strjoin(3, var.before, var.value, var.after);
	free(*value);
	*value = new_str;
	free_var_struct(&var);
	expand_variables(value);
}
