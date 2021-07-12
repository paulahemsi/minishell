/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:31:27 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/08 21:30:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# define BLACK "\001\033[0;30m\002"
# define BOLD_BLACK "\001\033[1;30m\002"
# define RED "\001\033[0;31m\002"
# define BOLD_RED "\001\033[1;31m\002"
# define GREEN "\001\033[0;32m\002"
# define BOLD_GREEN "\001\033[1;32m\002"
# define YELLOW "\001\033[0;33m\002"
# define BOLD_YELLOW "\001\033[1;33m\002"
# define BLUE "\001\033[0;34m\002"
# define BOLD_BLUE "\001\033[1;34m\002"
# define PURPLE "\001\033[0;35m\002"
# define BOLD_PURPLE "\001\033[1;35m\002"
# define CYAN "\001\033[0;36m\002"
# define BOLD_CYAN "\001\033[1;36m\002"
# define WHITE "\001\033[0;37m\002"
# define BOLD_WHITE "\001\033[1;37m\002"
# define RESET_COLOR "\001\033[0m\002"

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>

char	*create_prompt(void);

#endif
