/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:17:17 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/07 16:15:04 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

/*
** ERROR MESSAGE MACROS:
*/

# define NOT_FOUND "command not found."

# define TOO_MANY_ARGS "too many arguments."

# define NO_OLDPWD "OLDPWD environment variable has not been set."

# define NO_HOME "HOME environment variable has not been set."

# define NO_FILE_OR_DIR "no such file or directory."

# define SYNTAX_ERROR "syntax error."

# define NUM_ARG_REQUIRED "numeric argument required."

/*
** ERROR HANDLING FUNCTIONS:
*/

void	error_message(char *input, char *error_message, int status);

#endif
