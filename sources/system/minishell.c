/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:28:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/07/20 18:12:13 by lfrasson         ###   ########.fr       */
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
	char	**cmd;

	if (ft_strncmp("exit", input, 5) == 0)
		exit(0);
	if (ft_strcmp("bad-command", input) == 0)
	{
		error_message(input, NOT_FOUND);
		return ;
	}
	if (ft_strcmp("env", input) == 0)
		print_environment(g_minishell.env, STDOUT_FILENO);
	if (ft_strncmp("unset ", input, 6) == 0)
	{
		cmd = ft_split(input, ' ');
		unset(cmd[1]);
		free_2d_array(cmd);
	}
	if (ft_strncmp("export", input, 6) == 0)
	{
		cmd = ft_split(input, ' ');
		export(cmd, STDOUT_FILENO);
		free_2d_array(cmd);
	}
	if (ft_strncmp("pwd", input, 3) == 0)
		pwd();
}

static void	repl(void)
{
	char	*input;
	t_token	*token_lst;

	while (true)
	{
		token_lst = NULL;
		define_input_signals();
		read_input(&input);
		save_history(input);
		tokenizer(input, &token_lst);
		token_list_clear(&token_lst);
		execute(input);
		free(input);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1 && argv)
		error_message("👿", TOO_MANY_ARGS);
	g_minishell.env = env_to_hashmap(__environ);
	g_minishell.local_vars = hashmap_create_table(50);
	g_minishell.input_fd = STDIN_FILENO;
	g_minishell.output_fd = STDOUT_FILENO;
	repl();
	return (0);
}
