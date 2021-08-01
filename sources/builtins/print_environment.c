/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 01:48:59 by user42            #+#    #+#             */
/*   Updated: 2021/08/01 11:40:46 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_environment(t_hashmap *env, int fd)
{
	char	**env_array;

	g_minishell.error_status = 0;
	env_array = hashmap_to_env(env);
	print_2d_array_fd(env_array, fd);
	free_2d_array(env_array);
}
