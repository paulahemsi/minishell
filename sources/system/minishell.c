/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:28:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/28 17:20:21 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void temporary_loop(void)
{
	char *input;

	while(true)
	{
		ft_printf("Digite algo: ");
		get_next_line(0, &input);
		if (ft_strncmp("exit", input, 5) == 0)
			exit(0);
		ft_printf("Você digitou: %s\n", input);
		free(input);
	}
}

int	main(void)
{
	//pegar variáveis de ambiente
	//inicializar structs
	//inicializar ambiente
	//termcaps
	temporary_loop();
	//while (true)
	//{
    //	printar o prompt
    //	lidar com signals
    //	ler o que pessoa escreveu
    //	tokenizar
	//	parser
    //	executar
    //	free nas coisa tudo
	//	}
	return (0);
}
