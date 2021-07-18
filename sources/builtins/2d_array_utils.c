/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:42:27 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/18 18:21:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_2d_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i + 1])
		i++ ;
	return (i);
}

void	join_2d_array(char *string_to_join, char **array)
{
	int		i;
	char	*temp;

	i = 0;
	while (array[i])
	{
		temp = ft_strjoin(string_to_join, array[i]);
		free(array[i]);
		array[i] = temp;
		i++;
	}
}

void	print_2d_array_fd(char **array, int fd)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putendl_fd(array[i], fd);
		i++;
	}
}

void	free_2d_array(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}
