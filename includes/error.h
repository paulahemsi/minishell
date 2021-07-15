/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:17:17 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/15 01:35:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

/*
** ERROR MESSAGE MACROS:
*/

# define NOT_FOUND "command not found."

# define TOO_MANY_ARGS "this program doesn't expect any arguments."

/*
** ERROR HANDLING FUNCTIONS:
*/

void	error_message(char *input, char *error_message);

#endif