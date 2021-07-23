/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:25:29 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/22 22:27:15 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_absolute_path(char *cmd)
{
	struct stat	buffer;
	char		**all_paths;
	char		*path_variable;
	char		*cmd_path;
	int			i;

	i = 0;
	path_variable = hashmap_search(g_minishell.env, "PATH");
	all_paths = ft_split(path_variable, ':');
	while (all_paths && all_paths[i])
	{
		cmd_path = variadic_strjoin(3, all_paths[i], "/", cmd);
		if (stat(cmd_path, &buffer) == 0)
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	free_2d_array(all_paths);
	return (cmd_path);
}
