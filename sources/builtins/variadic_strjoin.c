/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 21:43:27 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/18 04:20:49 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Note to the user: variadic function argument lists are NOT null terminated and
** there is no way to test if the list is over. Therefore, this function trusts
** the user to enter the correct quantity of arguments, otherwise it'll segfault.
*/

char	*variadic_strjoin(unsigned int arg_quantity, ...)
{
	va_list			arg_list;
	unsigned int	i;
	char			*arg_buffer;
	char			*temp;
	char			*result;

	va_start(arg_list, arg_quantity);
	i = 0;
	result = NULL;
	while (i < arg_quantity)
	{
		arg_buffer = va_arg(arg_list, char *);
		if (result == NULL)
			result = ft_strdup(arg_buffer);
		else
		{
			temp = ft_strjoin(result, arg_buffer);
			free(result);
			result = temp;
		}
		i++;
	}
	va_end(arg_list);
	return (result);
}
