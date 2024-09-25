/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosleima <mosleima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:26:49 by mosleima          #+#    #+#             */
/*   Updated: 2024/09/25 11:46:24 by mosleima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				index;
	int				push_cost;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target_node;
}					t_node;

int					ft_atoi_safe(const char *str, int *error);
int					calculate_individual_cost(int index, int len);
void				calculate_push_cost(t_node *a, t_node *b);
t_node				*find_cheapest(t_node *a);
void				parse_string_to_list(t_node **head, const char *input);
void				parse_argv_to_list(t_node **head, int argc, char **argv);
void				add_node_at_head(t_node **head, t_node *new_node);
t_node				*get_tail(t_node *list);
void				add_tail(t_node **head, int data);
void				del_head(t_node **s);
void				move_a_b_to_top(t_node **a, t_node **b);
void				move_to_top(t_node **stack, t_node *node, char stack_name);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				rrb(t_node **b);
void				rra(t_node **a);
void				rrr(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				sa(t_node **a);
void				push_swap(t_node **a, t_node **b);
char				**ft_split(char const *s, char c);
void				ft_free_split(char **split, int word_index);
void				set_target_a(t_node *a, t_node *b);
void				set_target_b(t_node *a, t_node *b);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
void				handle_error(t_node **head, char **split);
void				update_indices(t_node *stack);
int					check_duplicates(t_node *head);
t_node				*min_node(t_node *head);
t_node				*max_node(t_node *head);
int					is_sorted(t_node *stack);
int					count_nodes(t_node *list);
void				sort_three(t_node **stack);


#endif
