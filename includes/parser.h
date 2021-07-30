/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:09:54 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/07/29 21:59:44 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "tokenizer.h"

# define IN		0
# define OUT	1

void	parse_and_execute(t_token *token_lst);
void	command_parser(t_token *token_lst, t_token *pipe);
void	check_redirects(t_token *token_lst, t_token *pipe);
char	**create_command_array(t_token *head, t_token *pipe);

#endif
