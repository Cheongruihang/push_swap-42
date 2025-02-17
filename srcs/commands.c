/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:21:26 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/23 19:20:17 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **any)
{
	if (!any || !*any)
		return ;
	*any = (*any)-> next;
	(*any)-> previous -> previous = *any;
	(*any)-> previous -> next = (*any)-> next;
	if ((*any)-> next)
		(*any)-> next -> previous = (*any)-> previous;
	(*any)-> next = (*any)-> previous;
	(*any)-> previous = NULL;
}

void	rotate(t_stack **any)
{
	t_stack	*last;

	if (!any || !*any)
		return ;
	last = lstlast(*any);
	last -> next = *any;
	(*any) = (*any)-> next;
	(*any)-> previous = NULL;
	last -> next -> previous = last;
	last -> next -> next = NULL;
}

void	reverse_rotate(t_stack **any)
{
	t_stack	*last;
	t_stack	*temp;

	if (!any || !*any)
		return ;
	last = lstlast(*any);
	temp = *any;
	while (temp -> next != last)
		temp = temp -> next;
	temp -> next = NULL;
	last -> next = *any;
	last -> previous = NULL;
	(*any) = last;
	last -> next -> previous = last;
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)-> next;
	if (*src)
		(*src)-> previous = NULL;
	temp->previous = NULL;
	if (!*dest)
	{
		*dest = temp;
		temp -> next = NULL;
	}
	else
	{
		temp -> next = *dest;
		temp->next->previous = temp;
		*dest = temp;
	}
}
