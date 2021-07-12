/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:40:26 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/11 18:08:57 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

/*
** ENV:
*/

t_hashmap	*env_to_hashmap(char **env);
char		**hashmap_to_env(t_hashmap *table);

#endif