/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_hashmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:04:52 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/18 18:21:10 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*env_array_find_value(char *env_line)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (env_line[i] != '=')
		i++;
	j = i;
	while (env_line[j])
		j++;
	value = ft_substr(env_line, i + 1, j);
	return (value);
}

static char	*env_array_find_key(char *env_line)
{
	int		i;
	char	*key;

	i = 0;
	while (env_line[i] != '=')
		i++;
	key = ft_substr(env_line, 0, i);
	return (key);
}

t_hashmap	*env_to_hashmap(char **env)
{
	int			len;
	int			i;
	t_hashmap	*table;
	char		*key;
	char		*value;

	len = 0;
	i = 0;
	while (env[len])
		len++;
	table = hashmap_create_table(len * 2);
	while (i < len)
	{
		key = env_array_find_key(env[i]);
		value = env_array_find_value(env[i]);
		hashmap_insert(key, value, table);
		i++;
		free(key);
		free(value);
	}
	return (table);
}
