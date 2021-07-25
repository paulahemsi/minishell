/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:40:26 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/25 03:06:45 by lcouto           ###   ########.fr       */
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
char		**hashmap_to_env_with_quotes(t_hashmap *table);

/*
** BUILTINS:
*/
void		print_environment(t_hashmap *env, int fd);
int			export(char **cmd);
void		unset(char **cmd);
void		pwd(void);
void		cd(char *path);
void		echo(char **cmd);
void		exit_minishell(void);

/**
** 2D ARRAY UTILS
*/

void		quick_sort_2d_array(char **array, int left, int right);
int			get_2d_array_len(char **array);
void		join_2d_array(char *string_to_join, char **array);

#endif
