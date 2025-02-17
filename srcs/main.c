/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:09:30 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/23 18:27:19 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	sorted(t_stack *a)
{
	t_stack	*temp;

	if (!a)
		exit_error("Error\n", &a);
	temp = a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (!argv)
		exit_error("Error\n", &a);
	create_stack_a(&a, argv + 1);
	if (!sorted(a))
	{
		if (lstsize(a) == 2)
			sa(&a);
		if (lstsize(a) == 3)
			tiny_sort(&a);
		if (lstsize(a) > 3)
			turk_sort(&a, &b);
	}
	free_stack(&a);
	return (0);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
