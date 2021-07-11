/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:57:34 by user42            #+#    #+#             */
/*   Updated: 2021/07/11 17:07:25 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_and_delete_node_then_relink_list(t_hashmap *table,
			t_pair *current, char *key)
{
	t_pair	*temp;

	while (current->next != NULL)
	{
		if (ft_strncmp(current->next->key, key, ft_strlen(key) + 1) == 0)
		{
			temp = current->next;
			current->next = current->next->next;
			hashmap_free_pair(temp);
			table->count -= 1;
			return ;
		}
		current = current->next;
	}
}

static void	free_current_and_relink_head(t_hashmap *table, t_pair *current,
			unsigned long int index)
{
	table->pairs[index] = current->next;
	hashmap_free_pair(current);
	table->count -= 1;
}

static void	free_head_and_set_to_null(t_hashmap *table, t_pair *current,
			unsigned long int index)
{
	hashmap_free_pair(current);
	table->pairs[index] = NULL;
	table->count -= 1;
}

void	hashmap_delete(t_hashmap *table, char *key)
{
	unsigned long int	index;
	t_pair				*current;

	index = hash(key, table->size);
	current = table->pairs[index];
	if (current == NULL)
		return ;
	else if (current->next == NULL
		&& ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
	{
		free_head_and_set_to_null(table, current, index);
		return ;
	}
	else if (current->next != NULL
		&& ft_strncmp(current->key, key, ft_strlen(key) + 1) == 0)
	{
		free_current_and_relink_head(table, current, index);
		return ;
	}
	else
		find_and_delete_node_then_relink_list(table, current, key);
}
