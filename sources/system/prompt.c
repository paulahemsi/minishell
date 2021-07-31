/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:40:47 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/31 15:29:35 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_pwd(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

static void	free_prompt_strings(char *name, char *pwd, char *end)
{
	free(name);
	free(pwd);
	free(end);
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
	free_prompt_strings(name, pwd, end);
	return (prompt);
}

static char	*create_name(bool *emoji)
{
	if (!*emoji)
	{
		*emoji = true;
		return (ft_strdup("xXXx MINIHELL xXXx:"));
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
