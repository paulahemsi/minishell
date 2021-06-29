/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:28:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/28 21:07:07 by lfrasson         ###   ########.fr       */
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
	ft_printf("%s\n", input);
}

static void	repl(void)
{
	char	*input;

	while (true)
	{
		display_prompt();
		//lidar com signals
		read_input(&input);
		//tokenizar
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
