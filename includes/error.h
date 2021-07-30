/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:17:17 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/29 21:40:39 by lfrasson         ###   ########.fr       */
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

# define NO_OLDPWD "OLDPWD environment variable has not been set."

# define NO_FILE_OR_DIR "no such file or directory."

# define SYNTAX_ERROR "syntax error."

/*
** ERROR HANDLING FUNCTIONS:
*/

void	error_message(char *input, char *error_message);

#endif
