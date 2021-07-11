/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:32:10 by user42            #+#    #+#             */
/*   Updated: 2021/07/11 18:18:00 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_pair
{
	char			*key;
	char			*value;
	struct s_pair	*next;
}				t_pair;

typedef struct s_hashmap
{
	t_pair			**pairs;
	unsigned int	count;
	unsigned int	size;

}				t_hashmap;

t_pair				*hashmap_create_pair(char *key, char *value);
t_hashmap			*hashmap_create_table(unsigned int size);
void				hashmap_free_pair(t_pair *pair);
void				hashmap_free_table(t_hashmap *table);
void				hashmap_insert(char *key, char *value, t_hashmap *table);
char				*hashmap_search(t_hashmap *table, char *key);
void				hashmap_handle_collision(t_hashmap *table,
						unsigned long int index, t_pair *new_pair);
void				hashmap_delete(t_hashmap *table, char *key);
void				hashmap_print_table(t_hashmap *table);
unsigned long int	hash(char *key, unsigned int size);

#endif