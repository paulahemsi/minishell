/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:59:44 by user42            #+#    #+#             */
/*   Updated: 2021/07/11 02:44:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

/*
** This function is an implementation of the djb2 hashing algorithm.
** Further info: https://theartincode.stanis.me/008-djb2/
*/

unsigned long int	hash(char *key, unsigned int size)
{
	unsigned long int	hash;
	unsigned int		i;

	hash = 5381;
	i = 0;
	while (key && key[i])
	{
		hash = ((hash << 5) + hash) + key[i];
		i++;
	}
	return (hash % size);
}
