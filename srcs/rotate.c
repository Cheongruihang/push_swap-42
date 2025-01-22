/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:30:00 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/12 19:30:00 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_both_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while((*a) != cheapest && (*b) != cheapest->target)
        rr(a, b);
    current_index(a);
    current_index(b);
}
void reverse_rotate_both_a(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while((*a) != cheapest && (*b) != cheapest->target)
        rrr(a, b);
    current_index(a);
    current_index(b);
}
void rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while((*b) != cheapest && (*a) != cheapest->target)
        rr(a, b);
    current_index(a);
    current_index(b);
}

//here changed
void reverse_rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while((*b) != cheapest && (*a) != cheapest->target)
        rrr(a, b);
    current_index(a);
    current_index(b);
}