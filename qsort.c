/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:59:03 by solivari          #+#    #+#             */
/*   Updated: 2019/08/26 09:58:05 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setgroup(t_body *stacka, int gp, int range)
{
	t_body	*cursor;

	cursor = stacka->next;	
	while (cursor->next)
	{
		if (cursor->dx <= range && !cursor->gp)
			cursor->gp = gp;
		cursor = cursor->next;
	}
}

void   group(t_body **stacka, int size)
{
	int		min;
	int		max;
	int		range = (size / 5);
	int		add = (size / 5);
	
	setgroup(*stacka, 1, range);
	range += add;
	setgroup(*stacka, 2, range);
	range += add;
	setgroup(*stacka, 3, range);
	range += add;
	setgroup(*stacka, 4, range);
	range += add;
	setgroup(*stacka, 5, range);
}