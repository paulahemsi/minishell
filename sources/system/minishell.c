/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:28:42 by lcouto            #+#    #+#             */
/*   Updated: 2021/06/27 18:01:35 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char *input;

	while(true)
	{
		ft_printf("Digite algo: ");
		get_next_line(0, input);
		if (ft_strncmp("exit", input, 5) == 0)
			exit(0);
		ft_printf("Você digitou: %s\n", input);
		free(input);
	}
	return (0);
}