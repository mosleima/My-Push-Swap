/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:25:17 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/13 18:26:04 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		parse_string_to_list(&a, argv[1]);
	else if (argc > 2)
		parse_argv_to_list(&a, argc, argv);
	else
		return (0);
	if (!is_sorted(a))
		push_swap(&a, &b);
	while (a)
		del_head(&a);
	while (b)
		del_head(&b);
	return (0);
}
