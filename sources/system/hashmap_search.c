/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 00:00:31 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 00:07:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

char	*hashmap_search(t_hashmap *table, char *key)
{
	unsigned long int index;

	index = hash(key, table->size);
	if (table->pairs[index] != NULL)
	{
		if (strncmp(table->pairs[index]->key, key, ft_strlen(key) + 1) == 0)
			return (table->pairs[index]->value);
	}
	return (NULL);
}