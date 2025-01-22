/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:35:55 by chrui-ha          #+#    #+#             */
/*   Updated: 2025/01/11 14:35:55 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack **stack)
{
    t_stack *temp;

    while(*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    free(*stack);
}

void exit_error(char *str, t_stack **stack)
{
    int i;

    i = ft_strlen(str);
    write(2, str, i);
    free_stack(stack);
    exit(1);
}

int error_duplicate(t_stack *stack, int data)
{
    t_stack *temp;

    temp = stack;
    while(temp)
    {
        if(temp->data == data)
            return(1);
        temp = temp->next;
    }
    return(0);
}

int error_digit(char *str)
{
    int i;

    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    while(str[i])
    {
        if(!ft_isdigit(str[i]))
            return(1);
        i++;
    }
    return(0);
}