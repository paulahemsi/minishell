/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_free_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:04:20 by user42            #+#    #+#             */
/*   Updated: 2021/07/11 02:48:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void	hashmap_free_table(t_hashmap *table)
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
			hashmap_free_pair(current);
			current = temp;
		}
		i++;
	}
	free(table->pairs);
	free(table);
}
