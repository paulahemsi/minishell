/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:29:00 by lfrasson          #+#    #+#             */
/*   Updated: 2021/09/30 14:24:33 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_string_number(char *string)
{
	while (*string)
		if (!ft_isdigit(*string++))
			return (FALSE);
	return (TRUE);
}

static void	parse_first_arg(char *arg)
{
	if (!arg)
		return ;
	g_minishell.error_status = ft_atoi(arg);
	if (is_string_number(arg))
		return ;
	error_message("exit", NUM_ARG_REQUIRED, 2);
	exit_minishell();
}

static int	get_argc(char **argv)
{
	int	argc;

	argc = 0;
	while (*(++argv))
		argc++;
	return (argc);
}

void	exit_builtin(char **argv)
{
	int	argc;

	argc = get_argc(argv);
	parse_first_arg(*(argv + 1));
	if (argc > 1)
	{
		error_message("exit", TOO_MANY_ARGS, 1);
		return ;
	}
	ft_printf("exit\n");
	exit_minishell();
}
