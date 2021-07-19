/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 10:53:17 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/18 21:30:30 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_builtin(char *value)
{
	if (!(ft_strcmp(value, "echo\0")) || !(ft_strcmp(value, "cd\0")))
		return (TRUE);
	if (!(ft_strcmp(value, "pwd")) || !(ft_strcmp(value, "export")))
		return (TRUE);
	if (!(ft_strcmp(value, "unset")) || !(ft_strcmp(value, "env")))
		return (TRUE);
	if (!(ft_strcmp(value, "exit")))
		return (TRUE);
	return (FALSE);
}

static bool	is_operator(char *value)
{
	if (!(ft_strcmp(value, "|")) || !(ft_strcmp(value, "=")))
		return (TRUE);
	if (!(ft_strcmp(value, ">")) || !(ft_strcmp(value, "<")))
		return (TRUE);
	if (!(ft_strcmp(value, ">>")) || !(ft_strcmp(value, "<<")))
		return (TRUE);
	return (FALSE);
}

void	define_type(char *value, int *type)
{
	if (is_builtin(value))
		*type = T_BUILTIN;
	else if (is_operator(value))
		*type = T_OPERATOR;
	else
		*type = T_LITERAL;
}
