/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:38:15 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/23 18:44:40 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack **a)
{
	t_stack	*temp;
	int		i;
	int		median;

	i = 0;
	if (!a || !*a)
		return ;
	temp = *a;
	median = lstsize(*a) / 2;
	while (temp)
	{
		temp->index = i;
		if (temp->index <= median)
			temp->high_median = true;
		else
			temp->high_median = false;
		temp = temp->next;
		i++;
	}
}

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		best_match = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->data < a -> data
				&& current_b->data > best_match)
			{
				best_match = current_b->data;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == INT_MIN)
			a->target = find_biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	cost_analysis_a(t_stack *a, t_stack *b)
{
	int	l_a;
	int	l_b;

	l_a = lstsize(a);
	l_b = lstsize(b);
	while (a)
	{
		a->cost = a->index;
		if (!a->high_median)
			a ->cost = l_a - a->index;
		if (a->target -> high_median)
			a->cost += a->target->index;
		else
			a->cost += l_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *a)
{
	t_stack	*node;
	long	cheapest;

	if (!a)
		return ;
	cheapest = INT_MAX;
	while (a)
	{
		if (a ->cost < cheapest)
		{
			cheapest = a->cost;
			node = a;
		}
		a = a->next;
	}
	node->cheapest = true;
}

void	initialise_a(t_stack *a, t_stack *b)
{
	current_index(&a);
	current_index(&b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
