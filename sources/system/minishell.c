/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:28:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/08 21:24:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	save_history(char *input)
{
	if (input && *input)
		add_history(input);
}

static void	read_input(char **input)
{
	char	*prompt;

	prompt = create_prompt();
	*input = readline(prompt);
	free(prompt);
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
	//char	*prompt;
	
	//prompt = create_prompt();
	//while ((input = readline(">> ")) != NULL)
	//while ((input = readline(prompt)) != NULL)
	while (true)
	{
		token_lst = NULL;
		//lidar com signals
		read_input(&input);
		save_history(input);
		tokenizer(input, &token_lst);
		//parser
		//executar
		token_list_clear(&token_lst);
		execute(input);
		//free nas coisa tudo
		free(input);
	}
	//free(prompt);
}

int	main(void)
{
	//pegar variáveis de ambiente
	//inicializar structs
	//inicializar ambiente
	//termcaps
	using_history();
	repl();
	return (0);
}
