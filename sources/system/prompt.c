/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:40:47 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/28 21:16:12 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

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

static void	print_prompt(char *name, char *pwd, char *end)
{
	ft_putstr_fd(BOLD_RED, 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(BOLD_PURPLE, 1);
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd(BOLD_RED, 1);
	ft_putstr_fd(end, 1);
	ft_putstr_fd(RESET_COLOR, 1);
}

void	display_prompt(void)
{
	char	*name;
	char	*pwd;
	char	*end;
	char	prompt_len;

	pwd = get_pwd();
	name = ft_strdup("😈🔥 MINIHELL 🔥😈:");
	end = ft_strdup("$ ");
	print_prompt(name, pwd, end);
	prompt_len = get_prompt_len(name, pwd, end);
	free_prompt_strings(name, pwd, end);
}
