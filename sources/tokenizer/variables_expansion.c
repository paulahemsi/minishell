/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:25:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/30 17:32:07 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_auxiliary_strings(char **temp, char **aux, char **splited_str)
{
	ft_free_and_null((void **)temp);
	ft_free_and_null((void **)aux);
	free_2d_array(splited_str);
}

static void	handle_quote(t_var *var, char **value, int i)
{
	char	**splited_string;
	char	*temp;
	char	*aux;

	splited_string = ft_split(var->value, SINGLE_QUOTE);
	ft_free_and_null((void **)&var->value);
	var->value = ft_strdup(splited_string[0]);
	if (splited_string[1])
		temp = ft_strjoin("\'", splited_string[1]);
	else
		temp = ft_strdup("\'");
	aux = ft_substr(*value, i, (ft_strlen(*value) - i));
	var->after = ft_strjoin(temp, aux);
	free_auxiliary_strings(&temp, &aux, splited_string);
}

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
		handle_quote(var, value, *i);
	else
		var->after = ft_substr(*value, *i, (ft_strlen(*value) - *i));
	expand(&var->value);
}

void	expand_variables(char **value)
{
	t_var	var;
	char	*new_str;
	int		i;

	i = 0;
	if (!(*value) || is_exit_status_variable(value))
		return ;
	var.pointer = search_var(*value, &i);
	if (!(var.pointer))
		return ;
	deal_with_string_slices(&var, value, &i);
	new_str = variadic_strjoin(3, var.before, var.value, var.after);
	free(*value);
	*value = new_str;
	free_var_struct(&var);
	expand_variables(value);
}
