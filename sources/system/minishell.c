/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:28:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/11 20:10:17 by lcouto           ###   ########.fr       */
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
}

int	main(void)
{
	//pegar variáveis de ambiente
	// - SEQUÊNCIA DE TESTE - START
	t_hashmap	*env_map;
	char		**env_array;

	print_2d_array_fd(__environ, 1);
	env_map = env_to_hashmap(__environ);
	hashmap_print_table(env_map);
	env_array = hashmap_to_env(env_map);
	print_2d_array_fd(env_array, 1);
	hashmap_free_table(env_map);
	// - SEQUÊNCIA DE TESTE - STOP
	//inicializar structs
	//inicializar ambiente
	//termcaps
	repl();
	return (0);
}
