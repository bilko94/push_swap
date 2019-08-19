/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:34:08 by solivari          #+#    #+#             */
/*   Updated: 2019/08/19 15:40:58 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int        checksort(t_body *stacka, t_body *stackb, t_flgs *flags)
{
    stacka = stacka->next;
    while (stacka->next)
    {
        if (stackb->next != NULL)
            return (0);
        if (stacka->value > stacka->next->value)
	    { 
            // ft_putendl("K.O!");
            return(0);
        }
        stacka = stacka->next;
    }
    ft_putendl("OK!");
    return (1);   
}