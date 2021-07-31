/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 20:31:27 by lfrasson          #+#    #+#             */
/*   Updated: 2021/07/31 18:37:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>

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

/*
 * Escaped color codes for readline library
 */

# define ESC_BLACK "\001\033[0;30m"
# define ESC_BOLD_BLACK "\001\033[1;30m\002"
# define ESC_RED "\001\033[0;31m\002"
# define ESC_BOLD_RED "\001\033[1;31m\002"
# define ESC_GREEN "\001\033[0;32m\002"
# define ESC_BOLD_GREEN "\001\033[1;32m\002"
# define ESC_YELLOW "\001\033[0;33m\002"
# define ESC_BOLD_YELLOW "\001\033[1;33m\002"
# define ESC_BLUE "\001\033[0;34m\002"
# define ESC_BOLD_BLUE "\001\033[1;34m\002"
# define ESC_PURPLE "\001\033[0;35m\002"
# define ESC_BOLD_PURPLE "\001\033[1;35m\002"
# define ESC_CYAN "\001\033[0;36m\002"
# define ESC_BOLD_CYAN "\001\033[1;36m\002"
# define ESC_WHITE "\001\033[0;37m\002"
# define ESC_BOLD_WHITE "\001\033[1;37m\002"
# define ESC_RESET_COLOR "\001\033[0m\002"

# define WELCOME_MESSAGE "\n \
\001\033[1;33m\002           /\001\033[1;31m\002yssss\001\033[0;31m\002sssyyyssssssssssssssssssssssssssssssyyysss\001\033[1;31m\002ssssy\001\033[1;33m\002/`.--...``/-. \n \
\001\033[1;33m\002.`         /\001\033[1;31m\002mssss\001\033[0;31m\002ssssssssssssssssssssssssssssssssssssssssss\001\033[1;31m\002ssssm\001\033[1;33m\002+``:-..:/:++` \n \
\001\033[1;33m\002.//:` ```  /\001\033[1;31m\002mdss\001\033[0;31m\002sssssss+osssssssssssssssssssssssssso+sssssss\001\033[1;31m\002ssdm\001\033[1;33m\002/`:o...`.:oo: \n \
\001\033[1;33m\002`:+oo/.```.+\001\033[1;31m\002dNNy\001\033[0;31m\002ssssss+` .:+osssssssssssssssssso+:. `+ssssss\001\033[1;31m\002yNNN\001\033[1;33m\002+`-:..``-+oo/ \n \
\001\033[1;33m\002 ``+ooo:.-./\001\033[1;31m\002smms\001\033[0;31m\002sssssssso:. `-+osssssssssssso+-` .:ossssssss\001\033[1;31m\002smNm\001\033[1;33m\002+.````.:oooo/ \n \
\001\033[1;33m\002  `/oooo/../\001\033[1;31m\002mmss\001\033[0;31m\002sssssssssso/.   -- .ssss. --   ./ossssssssss\001\033[1;31m\002ssmm\001\033[1;33m\002+```./oooooo: \n \
\001\033[1;33m\002  `/ooooo:.+\001\033[1;31m\002Nys\001\033[0;31m\002ssssssssss:       ` .ssss. `       :ssssssssss\001\033[1;31m\002sym\001\033[1;33m\002/.:+ooooooo+- \n \
\001\033[1;33m\002  `oooooo+`/\001\033[1;31m\002hss\001\033[0;31m\002ssssssssso        :oossssoo:        osssssssss\001\033[1;31m\002sss\001\033[1;33m\002oooooooooo+.. \n \
\001\033[1;33m\002  :ooooooo`/\001\033[1;31m\002sss\001\033[0;31m\002ssssssssso.       +ssssssss+       .osssssssss\001\033[1;31m\002sso\001\033[1;33m\002oo+++oooo:``` \n \
\001\033[1;33m\002 `oooooooo`:\001\033[1;31m\002sss\001\033[0;31m\002sssssssssso/.``.:osssssssssso:.``./ossssssssss\001\033[1;31m\002sss\001\033[1;33m\002+/:+ooo/.```` \n \
\001\033[1;33m\002 /ooo/+ooo`-\001\033[1;31m\002sss\001\033[0;31m\002ssssssssssssssssssssssssssssssssssssssssssssss\001\033[1;31m\002sss\001\033[1;33m\002/:+oo+.``.::` \n \
\001\033[1;33m\002.ooo+:/ooo`:\001\033[1;31m\002sss\001\033[0;31m\002ssssssssssssssssssssssssssssssssssssssssssssss\001\033[1;31m\002sss\001\033[1;33m\002/+oo+.`.+o+-. \n \
\001\033[1;33m\002/ooo/:/ooo-/\001\033[1;31m\002ssss\001\033[0;31m\002ssssssssss../osssssssssssssssso/..ssssssssss\001\033[1;31m\002ssss\001\033[1;33m\002+ooo:.:ooo::: \n \
\001\033[1;33m\002ooo+:::+oo+o\001\033[1;31m\002sssss\001\033[0;31m\002sssssssss+- `-/+osssssssso+/-` -+ssssssssss\001\033[1;31m\002sss\001\033[1;33m\002o+ooo`:oooo... \n \
\001\033[1;33m\002ooo+::::+oooo\001\033[1;31m\002ssss\001\033[0;31m\002ssssssssssso+-.` `..--..` `.:+ossssssssss\001\033[1;31m\002sssss\001\033[1;33m\002+/ooo-/oooo-`` \n \
\001\033[1;33m\002ooo+:::::/oooo\001\033[1;31m\002sssss\001\033[0;31m\002sssssssssssssso++////++osssssssssssssss\001\033[1;31m\002ssss\001\033[1;33m\002o::oooooo+oo+`` \n \
\001\033[1;33m\002ooo+:::::::/+o\001\033[1;31m\002sssssss\001\033[0;31m\002ssssssssssssssssssssssssssssssssss\001\033[1;31m\002ssssss\001\033[1;33m\002o:::/ooooo/+oo.` \n \
\001\033[1;33m\002oooo::::::::::/o\001\033[1;31m\002sssssss\001\033[0;31m\002sssssssssssssssssssssssssssssss\001\033[1;31m\002ssssss\001\033[1;33m\002+.`-:::+o+::+oo-` \n \
\001\033[1;31m\002(       ) \\__   __/ ( (    /| \\__   __/ |\\     /|(  ____ \\( \\      ( \\        \n \
| () () |    ) (    |  \\  ( |    ) (    | )   ( || (    \\/| (      | (        \n \
| || || |    | |    |   \\ | |    | |    | (___) || (__    | |      | |        \n \
| |(_)| |    | |    | (\\ \\) |    | |    |  ___  ||  __)   | |      | |        \n \
| |   | |    | |    | | \\   |    | |    | (   ) || (      | |      | |        \n \
| )   ( | ___) (___ | )  \\  | ___) (___ | )   ( || (____/\\| (____/\\| (____/\\  \n \
|/     \\| \\_______/ |/    )_) \\_______/ |/     \\|(_______/(_______/(_______/  \n\n"

char	*create_prompt(bool *emoji);
void	define_input_signals(void);
void	define_exec_signals(void);

#endif
