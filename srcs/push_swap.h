/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:10:04 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/10/07 15:10:04 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <limits.h>
#include <stdbool.h>


typedef struct s_stack{
    struct s_stack    *previous;
    int             data;
    int            index;
    int             cost;
    bool        cheapest;
    bool          high_median;
    struct s_stack    *target;
    struct s_stack    *next;
}          t_stack;

void exit_error(char *str, t_stack **stack);
int error_duplicate(t_stack *stack, int data);
void free_stack(t_stack **stack);
int error_digit(char *str);

int main(int argc, char **argv);

int lstsize (t_stack *lst);
void tiny_sort(t_stack **a);
t_stack	*lstlast(t_stack *lst);

void create_stack_a(t_stack **a, char **argv);
void store_node( t_stack **stack, int data);
void current_index(t_stack **a);
t_stack *find_biggest(t_stack *a);

void initialise_b(t_stack *a, t_stack*b);
void set_target_b(t_stack *a, t_stack *b);
t_stack *find_smallest(t_stack *node);

int sorted(t_stack *a);

void push_prepare(t_stack **a, t_stack *target, char stack);
void minimum_top (t_stack **a);
void push_b_a(t_stack **a, t_stack **b);
void push_a_b(t_stack **a, t_stack **b);
t_stack *find_cheapest(t_stack *a);

void rotate_both_a(t_stack **a, t_stack **b, t_stack *cheapest);
void reverse_rotate_both_a(t_stack **a, t_stack **b, t_stack *cheapest);
void rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest);
void reverse_rotate_both_b(t_stack **a, t_stack **b, t_stack *cheapest);

void tiny_sort(t_stack **a);
void turk_sort (t_stack **a, t_stack **b);

void swap(t_stack **any);
void rotate(t_stack **any);
void reverse_rotate(t_stack **any);
void push(t_stack **src , t_stack **dest);

void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **a, t_stack **b);

void  set_target_a (t_stack *a, t_stack *b);
void cost_analysis_a(t_stack *a, t_stack *b);
void set_cheapest(t_stack *a);
void initialise_a(t_stack *a, t_stack *b);


void print_stack(t_stack *stack ,char c);
void print_stack_median(t_stack *stack ,char c);
void print_stack_pointer (t_stack *stack ,char c);
#endif