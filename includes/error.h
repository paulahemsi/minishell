/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:17:17 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/29 21:47:29 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minishell.h"

/*
** ERROR MESSAGE MACROS:
*/

# define NOT_FOUND "command not found."

/*
** ERROR HANDLING FUNCTIONS:
*/

void	error_message(char *input, char *error_message);

#endif