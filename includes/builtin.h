/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 17:40:26 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/31 17:52:14 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

# define KEY	0
# define VALUE	1

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
void		exit_builtin(char **cmd);
void		exit_minishell(void);
int			set_local_variable(char **cmd, int *i);

/**
** 2D ARRAY UTILS
*/

void		quick_sort_2d_array(char **array, int left, int right);
int			get_2d_array_len(char **array);
void		join_2d_array(char *string_to_join, char **array);

#endif
