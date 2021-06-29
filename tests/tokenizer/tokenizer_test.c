/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phemsi-a <phemsi-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:59:00 by phemsi-a          #+#    #+#             */
/*   Updated: 2021/06/27 19:20:09 by phemsi-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

# define TOTAL_TESTS	4
# define CASE_1			"echo hi | cd .. | cat -e file.ext > new_file.ext"
# define CASE_2			"echo $NAME"
# define CASE_3			"echo \"$NAME\""
# define CASE_4			"echo \'$NAME\'"

static void	print_token_lst(t_token *token_lst)
{
	while (token_lst->next != NULL)
	{
		printf("type: %i value: %s\n", token_lst->type, token_lst->value);
		token_lst = token_lst->next;
	}
	printf("type: %i value: %s\n", token_lst->type, token_lst->value);
}

static char	*define_case(int id)
{
	char	*base;
	char	*case_id;
	char	*test_case;

	base = ft_strdup("CASE_");
	case_id = ft_itoa(id);
	test_case = ft_strjoin(base, case_id);
	free(case_id);
	free(base);
	return (test_case);
}

static void	exec_tests(int id)
{
	t_token	*token_lst;
	char	*test_case;

	token_lst = NULL;
	test_case = define_case(id);
	tokenizer(test_case, token_lst);
	print_token_lst(token_lst);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		while (i++ < TOTAL_TESTS)
			exec_tests(i);
	return (0);
}