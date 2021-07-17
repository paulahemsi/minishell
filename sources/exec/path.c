/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:25:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/17 20:05:36 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** TODO: Refactor this function so it's not absolutely disgusting. 
*/

char	*get_absolute_path(char *cmd)
{
	struct stat	buffer;
	char		**all_paths;
	char		*path_variable;
	char		*cmdpath;
	char		*temp;
	int			i;

	i = 0;
	path_variable = hashmap_search(g_minishell.env, "PATH");
	all_paths = ft_split(path_variable, ':');
	while (all_paths && all_paths[i])
	{
		temp = ft_strjoin("/", cmd);
		cmdpath = ft_strjoin(all_paths[i], temp);
		if (stat(cmdpath, &buffer) == 0)
			break;
		free(cmdpath);
		free(temp);
		cmdpath = NULL;
		i++;
	}
	free_2d_array(all_paths);
	free(path_variable);
	return (cmdpath);
}