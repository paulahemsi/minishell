/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 22:00:35 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/18 22:03:32 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_var(char *value, int *i)
{
	while (value[*i] != '\0')
	{
		if (value[*i] == '$')
			return (&value[*i]);
		*i += 1;
	}
	return (NULL);
}

int	get_var_size(char *var, int *index)
{
	int	i;

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
