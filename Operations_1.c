/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:51:58 by solivari          #+#    #+#             */
/*   Updated: 2019/07/15 16:51:50 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  sa(t_body **stacka)
{
    int  tmp;
    
    tmp = (*stacka)->next->value;
    (*stacka)->next->value = (*stacka)->value;
    (*stacka)->value = tmp;
}
