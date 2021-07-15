/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:40:47 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/15 01:23:20 by user42           ###   ########.fr       */
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

static int	get_prompt_len(char *name, char *pwd, char *end)
{
	int	len;

	len = ft_strlen(pwd);
	len += ft_strlen(name);
	len += ft_strlen(end);
	return (len);
}

static char	*concatenate_prompt(char *name, char *pwd, char *end)
{
	char	*temp;
	char	*prompt;

	prompt = ft_strjoin("\001\033[1;31m\002", name);
	temp = prompt;
	prompt = ft_strjoin(temp, "\001\033[1;35m\002");
	free(temp);
	temp = prompt;
	prompt = ft_strjoin(temp, pwd);
	free(temp);
	temp = prompt;
	prompt = ft_strjoin(temp, "\001\033[1;31m\002");
	free(temp);
	temp = prompt;
	prompt = ft_strjoin(temp, end);
	free(temp);
	temp = prompt;
	prompt = ft_strjoin(temp, "\001\033[0m\002");
	free(temp);
	free_prompt_strings(name, pwd, end);
	return (prompt);
}

char	*create_prompt(void)
{
	char	*name;
	char	*pwd;
	char	*end;
	char	prompt_len;

	pwd = get_pwd();
	name = ft_strdup("😈🔥 MINIHELL 🔥😈:");
	end = ft_strdup("$ ");
	prompt_len = get_prompt_len(name, pwd, end);
	return (concatenate_prompt(name, pwd, end));
}
