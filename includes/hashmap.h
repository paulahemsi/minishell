/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:32:10 by user42            #+#    #+#             */
/*   Updated: 2021/07/08 00:07:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHMAP_H
# define HASHMAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

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

t_pair	*hashmap_create_pair(char *key, char *value);
t_hashmap *hashmap_create_table(unsigned int size);
void	hashmap_free_pair(t_pair *pair);
void	hashmap_free_table(t_hashmap *table);
void	hashmap_insert(char *key, char *value, t_hashmap *table);
char	*hashmap_search(t_hashmap *table, char *key);
unsigned long int	hash(char *key, unsigned int length);

#endif