/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:28:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/08/03 09:19:46 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	save_history(char *input)
{
	if (input && *input)
		add_history(input);
}

static void	read_input(char **input, bool *emoji)
{
	char	*prompt;

	prompt = create_prompt(emoji);
	define_input_signals();
	*input = readline(prompt);
	free(prompt);
}

static void	repl(void)
{
	bool	emoji;
	char	*input;
	t_token	*token_lst;

	emoji = false;
	while (true)
	{
		token_lst = NULL;
		input = NULL;
		read_input(&input, &emoji);
		save_history(input);
		tokenizer(&input, &token_lst);
		parse_and_execute(token_lst);
		token_list_clear(&token_lst);
		if (input)
			free(input);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1 && argv)
		error_message("👿", TOO_MANY_ARGS, 666);
	g_minishell.env = env_to_hashmap(__environ);
	g_minishell.local_vars = hashmap_create_table(50);
	g_minishell.error_status = 0;
	repl();
	return (0);
}
