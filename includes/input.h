/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:31:27 by lfrasson          #+#    #+#             */
/*   Updated: 2021/06/30 19:35:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# define BLACK "\033[0;30m"
# define BOLD_BLACK "\033[1;30m"
# define RED "\033[0;31m"
# define BOLD_RED "\033[1;31m"
# define GREEN "\033[0;32m"
# define BOLD_GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BOLD_YELLOW "\033[1;33m"
# define BLUE "\033[0;34m"
# define BOLD_BLUE "\033[1;34m"
# define PURPLE "\033[0;35m"
# define BOLD_PURPLE "\033[1;35m"
# define CYAN "\033[0;36m"
# define BOLD_CYAN "\033[1;36m"
# define WHITE "\033[0;37m"
# define BOLD_WHITE "\033[1;37m"
# define RESET_COLOR "\033[0m"

# include "libft.h"

void	display_prompt(void);

#endif
