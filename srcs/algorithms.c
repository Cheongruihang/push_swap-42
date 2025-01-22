/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:39:20 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/11 22:39:20 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_biggest(t_stack *a) {
    t_stack *max = a; // Use a pointer to track the maximum

    while (a) {
        if (a->data > max->data) {
            max = a; // Update max to the current node
        }
        a = a->next;
    }
    return max; // Return the pointer to the node with the biggest value
}


void tiny_sort(t_stack **a)
{
    t_stack *largest;

    largest = find_biggest(*a);
    if (*a == largest)
        ra(a);
    else if ((*a) -> next == largest)
        rra(a);
    if( (*a) -> data > (*a) -> next -> data)
        sa(a);
}
void print_stack(t_stack *stack ,char c) {
    printf("Stack: %c",c);
    while (stack) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

void print_stack_median(t_stack *stack ,char c) {
    printf("Stack: %c",c);
    while (stack) {
        printf("%d ", stack-> high_median);
        stack = stack->next;
    }
    printf("\n");
}

void print_stack_target(t_stack *stack ,char c) {
    printf("Stack: %c",c);
    while (stack) {
        printf("%p ", stack-> target);
        stack = stack->next;
    }
    printf("\n");
}
void print_stack_pointer (t_stack *stack ,char c) {
    printf("Stack: %c",c);
    while (stack) {
        printf("%p ", stack);
        stack = stack->next;
    }
    printf("\n");
}
void turk_sort (t_stack **a, t_stack **b)
{
    int len;

    len = lstsize(*a);
    if(len-- > 3 && !sorted(*a))
      pb(a, b);
    //print_stack_target(*a,'a');
    //print_stack_pointer(*b,'b');
    if (len-- > 3 && !sorted(*a))
      pb(a, b);
    //print_stack_target(*a,'a');
    //print_stack_pointer(*b,'b');
    //print_stack(*a);
    //print_stack(*b);
    while (len-- > 3 && !sorted(*a))
    {
        initialise_a(*a, *b);
        push_a_b(a, b);
    }
    //print_stack_median(*a,'a');
    //print_stack_median(*b,'b');
    //print_stack_target(*a,'a');
    //print_stack_pointer(*b,'b');
    //print_stack(*a,'a');
    tiny_sort(a);
    //print_stack(*a,'a');
    //print_stack(*b,'b');
    while (*b)
    {
        initialise_b(*a, *b);
        push_b_a(a, b);
    }
    //current_index(a);
    minimum_top(a);

}