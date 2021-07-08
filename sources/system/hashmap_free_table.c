/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_free_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 02:04:20 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 00:13:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

void	hashmap_free_table(t_hashmap *table)
{
	unsigned int	i;

	i = 0;
	while (i < table->size)
	{
		if (table->pairs[i] != NULL)
			free(table->pairs[i]);
		i++;
	}
	free(table->pairs);
	free(table);
}