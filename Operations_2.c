/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:22:20 by solivari          #+#    #+#             */
/*   Updated: 2019/07/18 17:14:24 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_body **stacka)
{
    t_body  *cursorend;
    t_body  *secondlast;
    t_body  *firsta;
    t_body  *seconda;

    firsta = (*stacka)->next;
    seconda = firsta->next;
    cursorend = (*stacka);
    secondlast = (*stacka);
    while (cursorend->next)
        cursorend = cursorend->next;
    while (secondlast->next->next)
        secondlast = secondlast->next;
    if (cursorend != firsta)
    {
        cursorend->next = firsta;
        (*stacka)->next = cursorend;
        secondlast->next = NULL;
    }
}

void    rb(t_body **stackb)
{
    t_body  *cursorend;
    t_body  *secondlast;
    t_body  *firstb;
    t_body  *secondb;

    firstb = (*stackb)->next;
    secondb = firstb->next;
    cursorend = (*stackb);
    secondlast = (*stackb);
    while (cursorend->next)
        cursorend = cursorend->next;
    while (secondlast->next->next)
        secondlast = secondlast->next;
    if (cursorend != firstb)
    {
        cursorend->next = firstb;
        (*stackb)->next = cursorend;
        secondlast->next = NULL;
    }
}