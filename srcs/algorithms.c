/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:39:20 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/23 19:15:14 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest(t_stack *a)
{
	t_stack	*max;

	max = a;
	while (a)
	{
		if (a->data > max->data)
			max = a;
		a = a->next;
	}
	return (max);
}

void	tiny_sort(t_stack **a)
{
	t_stack	*largest;

	largest = find_biggest(*a);
	if (*a == largest)
		ra(a);
	else if ((*a)-> next == largest)
		rra(a);
	if ((*a)-> data > (*a)-> next -> data)
		sa(a);
}

void	turk_sort(t_stack **a, t_stack **b)
{
	int	len;

	len = lstsize(*a);
	if (len-- > 3 && !sorted(*a))
		pb(a, b);
	if (len-- > 3 && !sorted(*a))
		pb(a, b);
	while (len-- > 3 && !sorted(*a))
	{
		initialise_a(*a, *b);
		push_a_b(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		initialise_b(*a, *b);
		push_b_a(a, b);
	}
	current_index(a);
	minimum_top(a);
}
