/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_to_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:44:33 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/11 20:08:16 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pair_to_env_entry(t_pair *pair)
{
	char	*entry;
	char	*temp;

	temp = ft_strjoin(pair->key, "=");
	entry = ft_strjoin(temp, pair->value);
	free(temp);
	return (entry);
}

char	**hashmap_to_env(t_hashmap *table)
{
	unsigned int	i;
	unsigned int	j;
	t_pair			*current;
	t_pair			*temp;
	char			**env;

	i = 0;
	j = table->count;
	env = (char **)ft_calloc(sizeof (char *), table->count + 1);
	while (i < table->size)
	{
		current = table->pairs[i];
		while (current != NULL)
		{
			temp = current->next;
			env[j - 1] = pair_to_env_entry(current);
			current = temp;
			j--;
		}
		i++;
	}
	return (env);
}