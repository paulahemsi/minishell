/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:25:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/29 18:33:06 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static char	*search_var(char *value)
// {
// 	int i;

// 	i = 0;
// 	while (value[i] != '\0')
// 	{
// 		if (value[i] == '$')
// 			return (&value[i]);
// 		i++;
// 	}
// 	return (NULL);
// }

void	expand_variable(char **value)
{
	char	*temp;

	temp = ft_strdup("variable_value");//TODO buscar variável na hash table
	free(*value);
	*value = temp;
}

void	check_variables_inside_string(char **value)
{
	// char	*temp_before_var;
	// char	*temp_after_var;
	// char	*var_value;
	// char	*var_pointer;
	value++;
	value--;
	// var_pointer = search_var(*value);
	// if (var_pointer)
	// {
	// 	ft_strlcpy(temp_before_var, *value, i);
	// 	ft_strlcpy(var_value, value[i], );
	// 	ft_strlcpy(temp_after_var, );
	// 	//TODO mudar value ajustada para nova variável
	// 	check_variables_inside_string(value);
	// }
	// else
		return ;
}

