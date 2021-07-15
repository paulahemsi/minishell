/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:25:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/15 12:57:29 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*search_var(char *value, int *i)
{
	while (value[*i] != '\0')
	{
		if (value[*i] == '$')
			return (&value[*i]);
		*i += 1;
	}
	return (NULL);
}

static int	get_size(char *var, int *index)
{
	int i;

	i = 0;
	while ((var[i + 1] != ' ') && (var[i + 1] != '\0') && (var[i + 1] != '$'))
		i++;
	i++;
	*index += i;
	return (i);
}

void	free_var_struct(t_var *var)
{
	ft_free_and_null((void **)&var->before);
	ft_free_and_null((void **)&var->value);
	ft_free_and_null((void **)&var->after);
	ft_free_and_null((void **)&var->temp);
}

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

void	expand_variables(char **value)
{
	t_var	var;
	char	*new_str;
	int		i = 0;

	if (!(*value))
		return ;
	var.pointer = search_var(*value, &i);
	if (!(var.pointer))
		return ;
	var.before = ft_substr(*value, 0, i);
	var.value = ft_substr(*value, i, get_size(var.pointer, &i));
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
