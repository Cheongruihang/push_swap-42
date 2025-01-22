/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrui-ha <chrui-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:09:30 by chrui-ha          #+#    #+#             */
/*   Updated: 2024/10/07 15:09:30 by chrui-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_array (char **array)
{
    int i;

    i = 0;
    while(array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int sorted(t_stack *a)
{
    t_stack *temp;

    if (!a)
        exit_error("Error\n", &a);
    temp = a;
    while(temp->next)
    {
        if(temp->data > temp->next->data)
            return(0);
        temp = temp->next;
    }
    return(1);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    //char **data;

    a = NULL;
    b = NULL;
    if(argc < 2 ||(argc == 2 && !argv[1][0]))
        exit_error("Error\n", &a);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    if(!argv)
        exit_error("Error\n", &a);
    /*for (int i = 0; data[i]; i++)
    {
        printf("%s\n", data[i]);
    }*/
    create_stack_a(&a, argv + 1);
    
    // Use a temporary pointer to print the stack without modifying the original pointer
    //t_stack *temp = a;
   /* while (temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    // Calculate the size of the stack
    int size = lstsize(a);
    printf("Size of the stack: %d\n", size);*/
    if (!sorted(a))
    {
        if(lstsize(a) == 2)
           sa(&a);
        if(lstsize(a) == 3)
            tiny_sort(&a);
        if(lstsize(a) > 3 )
           turk_sort(&a, &b);
    }
    
    free_stack(&a);
    

    
    return (0);
}
