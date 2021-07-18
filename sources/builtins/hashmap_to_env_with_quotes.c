/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_to_env_with_quotes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:31:26 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/18 18:20:27 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*pair_to_env_entry_with_quotes(t_pair *pair)
{
	char	*entry;
	char	*temp;
	char	*aux;
	char	*value_with_quotes;

	if (pair->value[0])
	{
		temp = ft_strjoin(pair->key, "=");
		aux = ft_strjoin("\"", pair->value);
		value_with_quotes = ft_strjoin(aux, "\"");
		entry = ft_strjoin(temp, value_with_quotes);
		free(temp);
		free(aux);
		free(value_with_quotes);
	}
	else
		entry = ft_strdup(pair->key);
	return (entry);
}

char	**hashmap_to_env_with_quotes(t_hashmap *table)
{
	unsigned int	i;
	unsigned int	j;
	t_pair			*current;
	t_pair			*temp;
	char			**env;

	i = 0;
	j = 0;
	env = (char **)ft_calloc(sizeof (char *), table->count + 1);
	while (i < table->size && j < table->count)
	{
		current = table->pairs[i];
		while (current != NULL)
		{
			temp = current->next;
			env[j] = pair_to_env_entry_with_quotes(current);
			current = temp;
			j++;
		}
		i++;
	}
	return (env);
}
