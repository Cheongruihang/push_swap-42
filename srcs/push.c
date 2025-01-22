/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:52:47 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/12 18:52:47 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_cheapest(t_stack *a)
{
    t_stack *cheapest;

    cheapest = a;
    while (a)
    {
        if (a->cost < cheapest->cost)
            cheapest = a;
        a = a->next;
    }
    return cheapest;
}

void push_a_b(t_stack **a, t_stack **b)
{
    t_stack *chepeast;

    chepeast = find_cheapest(*a);
    if ( chepeast->high_median && chepeast->target->high_median)
        rotate_both_a(a, b, chepeast);
    else if (!(chepeast->high_median) && !(chepeast->target->high_median))
        reverse_rotate_both_a(a, b, chepeast);
    push_prepare(a, chepeast, 'a');
    push_prepare(b, chepeast->target, 'b');
    pb(a, b);
}

void push_b_a(t_stack **a, t_stack **b)
{
     t_stack *chepeast;

    chepeast = find_cheapest(*b);
    if ( chepeast->high_median && chepeast->target->high_median)
        rotate_both_b(a, b, chepeast);
    else if (!(chepeast->high_median) && !(chepeast->target->high_median))
        reverse_rotate_both_b(a, b, chepeast);
    push_prepare(b, chepeast, 'b');
    push_prepare(a, chepeast->target, 'a');
    pa(a, b);
}

void minimum_top (t_stack **a)
{
    while ((*a) -> data != find_smallest(*a) -> data)
    {
        if (find_smallest(*a) -> high_median)
            ra(a);
        else
            rra(a);
    }
}

void push_prepare(t_stack **a, t_stack *target, char stack)
{
    while (*a != target)
    {
        if (stack == 'a')
        {
            if (target -> high_median)
                ra(a);
            else
                rra(a);
        }
        else if (stack == 'b')
        {
            if (target -> high_median)
                rb(a);
            else
                rrb(a);
        }
    }
}