/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsorta.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:17:37 by solivari          #+#    #+#             */
/*   Updated: 2019/09/03 10:31:29 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	asort_a(t_body **stacka, t_body **stackb, int grp, double size)
{
	int			i;
	int			hold;
	int			range;
	t_body		*cursor;

	hold = 1;
	range = ft_list_size(*stacka) / 2;
	i = (((grp - 1) * (size / 5)) + 1);
	cursor = (*stacka)->next;
	while (cursor->dx != i && cursor && hold++)
		cursor = cursor->next;
	while ((*stacka)->next->dx != i)
	{
		if (hold <= range)
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
}

void	agroup_sort(t_body **stacka, t_body **stackb, int grp, double size)
{
	double	range;
	int		max;

	range = ft_list_size(*stackb) + 1;
	max = grp * (size / 5) + 1;
	while ((*stackb)->next != NULL)
	{
		range -= 1;
		max -= 1;
		ifb(stacka, stackb, max, range);
		write(1, "pa\n", 3);
		caller(stacka, stackb, "pa");
	}
}

void	agroup(t_body **stacka, double size)
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

void	call_sorta(t_body **stacka, t_body **stackb)
{
	int		grp;
	double	size;

	size = ft_list_size(*stacka);
	grp = 5;
	while (grp != 0)
	{
		group_push(stacka, stackb, grp);
		if (grp != 5)
			asort_a(stacka, stackb, (grp + 1), size);
		agroup_sort(stacka, stackb, grp, size);
		grp--;
	}
	final_sort(stacka, stackb);
}
