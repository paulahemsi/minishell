/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:25:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/26 22:36:45 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand(char **variable)
{
	char	*value;
	char	*key;
	char	*temp;

	temp = *variable;
	temp++;
	key = ft_strtrim(temp, "\"");
	value = ft_strdup(hashmap_search(g_minishell.env, key));
	if (!value)
		value = ft_strdup(hashmap_search(g_minishell.local_vars, key));
	if (!value)
		value = ft_strdup("");
	free(*variable);
	free(key);
	*variable = value;
}

static void	handle_quote(t_var *var, char **value, int i)
{
	char	**splited_string;
	char	*aux;

	splited_string = ft_split(var->value, SINGLE_QUOTE);
	ft_free_and_null((void **)&var->value);
	var->value = ft_strdup(splited_string[0]);
	if (splited_string[1])
		var->temp = ft_strjoin("\'", splited_string[1]);
	else
		var->temp = ft_strdup("\'");
	aux = ft_substr(*value, i, (ft_strlen(*value) - i));
	var->after = ft_strjoin(var->temp, aux);
	ft_free_and_null((void **)&var->temp);
	ft_free_and_null((void **)&aux);
	i = 0;
	while (splited_string[i])
	{
		ft_free_and_null((void **)&splited_string[i]);
		i++;
	}
	ft_free_and_null((void **)&splited_string);
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
	var.before = ft_substr(*value, 0, i);
	var.value = ft_substr(*value, i, get_var_size(var.pointer, &i));
	if (ft_strchr(var.value, SINGLE_QUOTE))
		handle_quote(&var, value, i);
	else
		var.after = ft_substr(*value, i, (ft_strlen(*value) - i));
	expand(&var.value);
	var.temp = ft_strjoin(var.before, var.value);
	new_str = ft_strjoin(var.temp, var.after);
	free(*value);
	*value = new_str;
	free_var_struct(&var);
	expand_variables(value);
}
