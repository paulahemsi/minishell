/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:43:47 by lfrasson          #+#    #+#             */
/*   Updated: 2021/08/01 11:54:38 by lfrasson         ###   ########.fr       */
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

	g_minishell.error_status = 0;
	cwd = get_current_working_directory();
	if (cwd)
		ft_printf("%s\n", cwd);
	else
		error_message("pwd", strerror(errno), 1);
	free(cwd);
}
