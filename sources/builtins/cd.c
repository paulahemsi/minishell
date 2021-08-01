/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:33:57 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/31 19:04:17 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_dir_to_path(char *path)
{
	char	*pwd;
	char	*error_msg;
	char	buffer[2048];

	pwd = getcwd(buffer, 2048);
	hashmap_insert("OLDPWD", pwd, g_minishell.env);
	if (chdir(path) != 0 && ft_strchr(path, '>') == NULL)
	{
		error_msg = ft_strjoin("cd: ", path);
		error_message(error_msg, strerror(errno));
		free(error_msg);
		g_minishell.error_status = 1;
		return ;
	}
	pwd = getcwd(buffer, 2048);
	hashmap_insert("PWD", pwd, g_minishell.env);
}

static void	change_dir_to_oldpwd(char *path)
{
	ft_printf("%s\n", path);
	change_dir_to_path(path);
}

static void	change_dir_to_home(void)
{
	char	*path;

	path = ft_strdup(hashmap_search(g_minishell.env, "HOME"));
	change_dir_to_path(path);
	free(path);
}

void	cd(char	*path)
{
	char	*current_path;

	if ((!path) || ft_strcmp(path, "~") == 0)
	{
		change_dir_to_home();
		return ;
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		current_path = ft_strdup(hashmap_search(g_minishell.env, "OLDPWD"));
		if (current_path == NULL)
		{
			error_message("cd", NO_OLDPWD);
			g_minishell.error_status = 1;
			return ;
		}
		change_dir_to_oldpwd(current_path);
	}
	else
	{
		current_path = ft_strdup(path);
		change_dir_to_path(current_path);
	}
	free(current_path);
}
