/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_pair.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:17:27 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 00:26:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashmap.h"

t_pair	*hashmap_create_pair(char *key, char *value)
{
	t_pair	*new_pair;

	new_pair = (t_pair *)ft_calloc(sizeof(t_pair), 1);
	new_pair->key = ft_strdup(key);
	new_pair->value = ft_strdup(value);
	return (new_pair);
}