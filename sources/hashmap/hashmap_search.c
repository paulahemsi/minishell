/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:00:31 by user42            #+#    #+#             */
/*   Updated: 2021/07/11 02:46:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

char	*hashmap_search(t_hashmap *table, char *key)
{
	unsigned long int	index;
	t_pair				*current;

	index = hash(key, table->size);
	current = table->pairs[index];
	while (current != NULL)
	{
		if (strncmp(current->key, key, ft_strlen(key) + 1) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
