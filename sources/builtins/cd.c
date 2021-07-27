/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:33:57 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/26 21:03:21 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_directory(char *path)
{
	char	*pwd;
	char	*buffer;

	hashmap_insert
	(
		"OLDPWD",
		hashmap_search(g_minishell.env, "PWD"),
		g_minishell.env
	);
	if (chdir(path) != 0 && ft_strchr(path, '>') == NULL)
	{
		error_message("cd", strerror(errno));
		g_minishell.error_status = 1;
		return ;
	}
	buffer = NULL;
	pwd = getcwd(buffer, 0);
	hashmap_insert("PWD", pwd, g_minishell.env);
	free(pwd);
}

void	cd(char	*path)
{
	if ((!path) || ft_strcmp(path, "~") == 0)
	{
		change_directory(hashmap_search(g_minishell.env, "HOME"));
		return ;
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		if (!hashmap_search(g_minishell.env, "OLDPWD"))
		{
			error_message("cd", NO_OLDPWD);
			g_minishell.error_status = 1;
			return ;
		}
		ft_printf("%s\n", hashmap_search(g_minishell.env, "OLDPWD"));
		change_directory(hashmap_search(g_minishell.env, "OLDPWD"));
	}
	else
		change_directory(path);
}
