/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:30:24 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/23 18:21:16 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	store_node( t_stack **stack, int data)
{
	t_stack	*new;
	t_stack	*temp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit_error("Error\n", stack);
	new->data = data;
	new->target = NULL;
	new->next = NULL;
	if (!*stack)
	{
		new->previous = NULL;
		*stack = new;
	}
	else
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new->previous = temp;
		temp->next = new;
	}
}

void	create_stack_a(t_stack **a, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		if (error_digit(argv[i]))
			exit_error("Error\n", a);
		j = ft_atoi(argv[i]);
		if (j < INT_MIN || j > INT_MAX)
			exit_error("Error\n", a);
		if (error_duplicate(*a, j))
			exit_error("Error\n", a);
		store_node(a, j);
		i++;
	}
}
