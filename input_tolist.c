/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tolist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:24:06 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/11 10:14:39 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_string_to_list(t_node **head, const char *input)
{
	char	**split;
	int		i;
	int		error;
	int		value;

	split = ft_split(input, ' ');
	if (!split)
		handle_error(head, NULL);
	i = 0;
	while (split[i])
	{
		value = ft_atoi_safe(split[i], &error);
		if (error)
			handle_error(head, split);
		add_tail(head, value);
		i++;
	}
	ft_free_split(split, i);
	if (check_duplicates(*head))
		handle_error(head, NULL);
	update_indices(*head);
}

void	parse_argv_to_list(t_node **head, int argc, char **argv)
{
	int	i;
	int	error;
	int	value;

	i = 1;
	while (i < argc)
	{
		value = ft_atoi_safe(argv[i], &error);
		if (error)
			handle_error(head, NULL);
		add_tail(head, value);
		i++;
	}
	if (check_duplicates(*head))
		handle_error(head, NULL);
	update_indices(*head);
}
