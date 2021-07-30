/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_var_single_quote.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:41:45 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/30 17:41:58 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_auxiliary_strings(char **temp, char **aux, char **splited_str)
{
	ft_free_and_null((void **)temp);
	ft_free_and_null((void **)aux);
	free_2d_array(splited_str);
}

static void	join_single_quote(char **splited_string, char **temp)
{
	if (splited_string[1])
		*temp = ft_strjoin("\'", splited_string[1]);
	else
		*temp = ft_strdup("\'");
}

void	handle_var_single_quote(t_var *var, char **value, int i)
{
	char	**splited_string;
	char	*temp;
	char	*aux;

	splited_string = ft_split(var->value, SINGLE_QUOTE);
	ft_free_and_null((void **)&var->value);
	var->value = ft_strdup(splited_string[0]);
	join_single_quote(splited_string, &temp);
	aux = ft_substr(*value, i, (ft_strlen(*value) - i));
	var->after = ft_strjoin(temp, aux);
	free_auxiliary_strings(&temp, &aux, splited_string);
}
