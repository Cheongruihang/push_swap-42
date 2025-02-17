/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:23:44 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/23 18:35:24 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *node)
{
	t_stack	*smallest ;

	if (!node)
		return (NULL);
	smallest = node;
	while (node)
	{
		if (node->data < smallest->data)
			smallest = node;
		node = node->next;
	}
	return (smallest);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_match;

	while (b)
	{
		best_match = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a -> data > b -> data
				&& current_a -> data < best_match)
			{
				best_match = current_a->data;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == INT_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	cost_analysis(t_stack *a, t_stack *b)
{
	int	l_a;
	int	l_b;

	l_a = lstsize(a);
	l_b = lstsize(b);
	while (b)
	{
		b->cost = b->index;
		if (!b->high_median)
			b ->cost = l_b - b->index;
		if (b->target -> high_median)
			b->cost += b->target->index;
		else
			b->cost += l_a - b->target->index;
		b = b->next;
	}
}

void	initialise_b(t_stack *a, t_stack*b)
{
	current_index(&a);
	current_index(&b);
	set_target_b(a, b);
	cost_analysis(a, b);
	set_cheapest(b);
}
