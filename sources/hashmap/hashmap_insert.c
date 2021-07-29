/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:56:48 by user42            #+#    #+#             */
/*   Updated: 2021/07/29 00:28:52 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		table->pairs[index] = new_pair;
		table->count += 1;
	}
	else
	{
		if (ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
		{
			free(current->value);
			current->value = ft_strdup(value);
			hashmap_free_pair(new_pair);
		}
		else
			hashmap_handle_collision(table, index, new_pair);
	}
}
