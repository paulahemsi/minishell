/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:43:47 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/26 21:05:27 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_current_working_directory(void)
{
	char	*buffer;

	buffer = NULL;
	return (getcwd(buffer, 0));
}

void	pwd(void)
{
	char	*cwd;

	cwd = get_current_working_directory();
	if (cwd)
		ft_printf("%s\n", cwd);
	else
	{
		error_message("pwd", strerror(errno));
		g_minishell.error_status = 1;
	}
	free(cwd);
}
