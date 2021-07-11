/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_handle_collision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:54:11 by user42            #+#    #+#             */
/*   Updated: 2021/07/11 17:07:25 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	hashmap_handle_collision(t_hashmap *table,
		unsigned long int index, t_pair *new_pair)
{
	t_pair	*current;

	current = table->pairs[index];
	while (current->next != NULL)
		current = current->next;
	current->next = new_pair;
	current->next->next = NULL;
	table->count += 1;
}
