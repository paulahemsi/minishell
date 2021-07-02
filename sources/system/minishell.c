/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:28:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/01 19:17:24 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_input(char **input)
{
	get_next_line(0, input);
}

static void	execute(char *input)
{
	if (ft_strncmp("exit", input, 5) == 0)
		exit(0);
	if (ft_strcmp("bad-command", input) == 0)
	{
		error_message(input, NOT_FOUND);
		return ;
	}
}

static void	repl(void)
{
	char	*input;
	t_token	*token_lst;

	while (true)
	{
		token_lst = NULL;
		display_prompt();
		//lidar com signals
		read_input(&input);
		tokenizer(input, &token_lst);
		token_list_clear(&token_lst);//!MISTERY
		//parser
		//executar
		execute(input);
		//free nas coisa tudo
		free(input);
	}
}

int	main(void)
{
	//pegar variáveis de ambiente
	//inicializar structs
	//inicializar ambiente
	//termcaps
	repl();
	return (0);
}
