/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_print_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:10:20 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/11 20:09:08 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hashmap_print_table(t_hashmap *table)
{
	unsigned int	i;
	t_pair			*current;
	t_pair			*temp;

	i = 0;
	while (i < table->size)
	{
		current = table->pairs[i];
		while (current != NULL)
		{
			temp = current->next;
			ft_putendl_fd("----------------------------", 1);
			ft_putstr("| ");
			ft_putstr(current->key);
			ft_putstr(" | = | ");
			ft_putstr(current->value);
			ft_putendl_fd(" |", 1);
			current = temp;
		}
		i++;
	}
	ft_putendl_fd("----------------------------", 1);
}
