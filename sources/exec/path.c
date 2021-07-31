/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:25:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/31 19:28:42 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_possible_path(char *envpath, char *cmd)
{
	char	*path;

	if (ft_strncmp(envpath, cmd, ft_strlen(envpath)) == 0)
		path = ft_strdup(cmd);
	else
		path = (variadic_strjoin(3, envpath, "/", cmd));
	return (path);
}

char	*get_absolute_path(char *cmd)
{
	struct stat	buffer;
	char		**all_paths;
	char		*path_variable;
	char		*cmd_path;
	int			i;

	i = 0;
	path_variable = hashmap_search(g_minishell.env, "PATH");
	if (!path_variable)
	{
		path_variable = hashmap_search(g_minishell.local_vars, "PATH");
			if (!path_variable)
				return (NULL);
	}
	all_paths = ft_split(path_variable, ':');
	while (all_paths && all_paths[i])
	{
		cmd_path = get_possible_path(all_paths[i], cmd);
		if (stat(cmd_path, &buffer) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	free_2d_array(all_paths);
	return (cmd_path);
}
