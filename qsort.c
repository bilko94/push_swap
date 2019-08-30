/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:59:03 by solivari          #+#    #+#             */
/*   Updated: 2019/08/30 20:40:35 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	caller(t_body **stacka, t_body **stackb, char *s)
{
	if (ft_strequ(s, "sa"))
		sa(stacka);
	else if (ft_strequ(s, "sb"))
		sb(stackb);
	else if (ft_strequ(s, "ss"))
		ss(stacka, stackb);
	else if (ft_strequ(s, "pa"))
		pa(stacka, stackb);
	else if (ft_strequ(s, "pb"))
		pb(stacka, stackb);
	else if (ft_strequ(s, "ra"))
		ra(stacka);
	else if (ft_strequ(s, "rb"))
		rb(stackb);
	else if (ft_strequ(s, "rr"))
		rr(stacka, stackb);
	else if (ft_strequ(s, "rra"))
		rra(stacka);
	else if (ft_strequ(s, "rrb"))
		rrb(stackb);
	else if (ft_strequ(s, "rrr"))
		rrr(stacka, stackb);
}

void	sort_a(t_body **stacka, t_body **stackb, int grp, double size)
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

void	group_sort(t_body **stacka, t_body **stackb, int grp, double size)
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

void	final_sort(t_body **stacka, t_body **stackb)
{
	int		range;
	int		hold;
	int		i;
	t_body	*cursor;

	i = 1;
	range = ft_list_size(*stacka) / 2;
	cursor = (*stacka)->next;
	while ((*stacka)->next->dx != 1)
	{
		if (cursor->dx == 1)
		{
			hold = i;
			while ((*stacka)->next != cursor)
				bestop(stacka, stackb, hold, range);
		}
		else
		{
			cursor = cursor->next;
			i++;
		}
	}
}

void	call_sort(t_body **stacka, t_body **stackb)
{
	int		grp;
	double	size;

	size = ft_list_size(*stacka);
	grp = 5;
	while (grp != 0)
	{
		group_push(stacka, stackb, grp);
		if (grp != 5)
			sort_a(stacka, stackb, (grp + 1), size);
		group_sort(stacka, stackb, grp, size);
		grp--;
	}
	final_sort(stacka, stackb);
}
