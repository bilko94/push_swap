/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:34:08 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 16:51:18 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksort(t_body *stacka, t_body *stackb)
{
	if (stacka->next != NULL && stackb->next == NULL)
		stacka = stacka->next;
	while (stacka->next)
	{
		if (stackb->next != NULL)
			return (0);
		if (stacka->value > stacka->next->value)
			return (0);
		stacka = stacka->next;
	}
	if (stackb->next != NULL)
		return (0);
	return (1);
}

int	falsechecksort(t_body *stacka)
{
	if (stacka->next != NULL)
		stacka = stacka->next;
	while (stacka->next)
	{
		if (stacka->value > stacka->next->value)
			return (0);
		stacka = stacka->next;
	}
	return (1);
}
