/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:57:45 by solivari          #+#    #+#             */
/*   Updated: 2019/08/30 20:52:54 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setgroup(t_body *stacka, int gp, int range)
{
	t_body	*cursor;

	cursor = stacka->next;
	while (cursor)
	{
		if (cursor->dx <= range && !cursor->gp)
			cursor->gp = gp;
		cursor = cursor->next;
	}
}

void	group(t_body **stacka, double size)
{
	double		range;
	double		add;

	range = size / 5;
	add = size / 5;
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

void	ifa(t_body **stacka, t_body **stackb, double hold, double range)
{
	if (hold <= (range / 2))
	{
		write(1, "ra\n", 3);
		caller(stacka, stackb, "ra");
	}
	else
	{
		write(1, "rra\n", 4);
		caller(stacka, stackb, "rra");
	}
}

void	group_push(t_body **stacka, t_body **stackb, int grp)
{
	double		range;
	double		hold;
	t_body		*cursor;

	hold = 1;
	range = ft_list_size(*stacka) + 1;
	cursor = (*stacka)->next;
	while (cursor)
	{
		if (cursor->gp == grp)
		{
			range -= 1;
			while ((*stacka)->next != cursor)
				ifa(stacka, stackb, hold, range);
			write(1, "pb\n", 3);
			caller(stacka, stackb, "pb");
			hold = 1;
			cursor = (*stacka)->next;
		}
		else
		{
			cursor = cursor->next;
			hold++;
		}
	}
}
