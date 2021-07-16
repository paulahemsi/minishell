/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 01:48:59 by user42            #+#    #+#             */
/*   Updated: 2021/07/16 00:34:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_environment(t_hashmap *env, int fd)
{
	char	**env_array;

	env_array = hashmap_to_env(env);
	print_2d_array_fd(env_array, fd);
	free_2d_array(env_array);
}