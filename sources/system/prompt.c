/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:40:47 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/31 22:52:25 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

static char	*concatenate_prompt(char *name, char *pwd, char *end)
{
	char	*prompt;

	prompt = variadic_strjoin(
			7,
			ESC_BOLD_RED,
			name,
			ESC_BOLD_PURPLE,
			pwd,
			ESC_BOLD_RED,
			end,
			ESC_RESET_COLOR);
	free(name);
	free(pwd);
	free(end);
	return (prompt);
}

static void	display_welcome_message(void)
{
	char	*path;
	char	*local_paths;
	char	**cmd;

	path = (ft_strdup(hashmap_search(g_minishell.env, "PATH")));
	local_paths = variadic_strjoin(7, path, ":",
			hashmap_search(g_minishell.env, "PWD"), ":",
			hashmap_search(g_minishell.env, "PWD"), "/sources/system", ":.");
	cmd = ft_split("welcome", ' ');
	hashmap_insert("PATH", local_paths, g_minishell.env);
	execute(cmd);
	free(path);
	free(local_paths);
	free_2d_array(cmd);
}

static char	*create_name(bool *emoji)
{
	if (!*emoji)
	{
		*emoji = true;
		display_welcome_message();
		return (ft_strdup("\n"));
	}
	if (g_minishell.error_status == 0)
		return (ft_strdup("😈🔥 MINIHELL 🔥😈:"));
	return (ft_strdup("👿🔥 MINIHELL 🔥👿:"));
}

char	*create_prompt(bool *emoji)
{
	char	*name;
	char	*pwd;
	char	*end;

	pwd = get_pwd();
	name = create_name(emoji);
	end = ft_strdup("$ ");
	return (concatenate_prompt(name, pwd, end));
}
