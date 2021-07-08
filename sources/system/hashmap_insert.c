/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:56:48 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 00:07:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void	hashmap_insert(char *key, char *value, t_hashmap *table)
{
	unsigned long int	index;
	t_pair				*new_pair;
	t_pair				*current;

	index = hash(key, table->size);
	new_pair = hashmap_create_pair(key, value);
	current = table->pairs[index];
	if (current == NULL)
	{
		if (table->count == table->size)
		{
			ft_putendl_fd("\033[1;33mERROR: Hashmap is full.\n\033[0m", 2);
			hashmap_free_pair(new_pair);
			return ;
		}
		table->pairs[index] = new_pair;
		table->count += 1;
	}
	else
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			return ;
		}
		else
		{
			//hashmap_handle_collision(table, new_pair);
			return;
		}
	}
}