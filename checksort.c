/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:34:08 by solivari          #+#    #+#             */
/*   Updated: 2019/08/28 15:09:02 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        checksort(t_body *stacka, t_body *stackb, t_flgs *flags)
{
    stacka = stacka->next;
    while (stacka->next)
    {
        if (stackb->next != NULL)
            ft_putendl("K.O!");
        if (stacka->value > stacka->next->value)
            ft_putendl("K.O!");
        stacka = stacka->next;
    }
    ft_putendl("OK!");
}