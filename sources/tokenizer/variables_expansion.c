/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:25:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/06 19:54:22 by phemsi-a         ###   ########.fr       */
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

void	expand(char **value)
{
	char	*temp;

	temp = ft_strdup("Variable_value");//TODO buscar variável na hash table
	free(*value);
	*value = temp;
}

void	expand_variables(char **value)
{
	t_var	var;
	char	*new_str;
	int		i = 0;

	var.pointer = search_var(*value, &i);
	if (!(var.pointer))
		return ;
	var.before = ft_substr(*value, 0, i);
	var.value = ft_substr(*value, i, get_size(var.pointer, &i));
	if (var.value[ft_strlen(var.value) - 1] == SINGLE_QUOTE)
	{
		var.temp = ft_substr(*value, i, (ft_strlen(*value) - i));
		var.after = ft_strjoin("\'", var.temp);
		free(var.temp);
	}
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
