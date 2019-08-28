/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:59:03 by solivari          #+#    #+#             */
/*   Updated: 2019/08/28 17:50:31 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	MOVES = 0;

void	caller(t_body **stacka, t_body **stackb, char *s)
{
	MOVES += 1;
	if(ft_strequ(s, "sa"))
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

void	group_push(t_body **stacka, t_body **stackb, int grp, t_flgs *flags)
{
	int		i;
	int		range;
	int		hold;
	t_body	*cursor;

	i = 1;
	range = ft_list_size(*stacka) + 1;
	cursor = (*stacka)->next;
	while (cursor)
	{
		if (cursor->gp == grp)
		{
			hold = i;
			range -= 1;
			while ((*stacka)->next != cursor)
			{
				if (hold <= (range / 2))
				{	
					vstk(*stacka, *stackb, flags);
					caller(stacka, stackb, "ra");
				}
				else
				{
					vstk(*stacka, *stackb, flags);
					caller(stacka, stackb, "rra");
				}
			}
			vstk(*stacka, *stackb, flags);
			printf("cursor = %d\n", cursor->value);
			printf("cursor = %d\n", cursor->gp);
			caller(stacka, stackb, "pb");
			vstk(*stacka, *stackb, flags);
			i = 1;
			cursor = (*stacka)->next;
		}
		else
		{
			cursor = cursor->next;
			i++;
		}
	}
}

void	sort_a(t_body **stacka, t_body **stackb, t_flgs *flags, int grp)
{
	int		i;
	int		hold;
	int		range;
	t_body	*cursor;

	hold = 1;
	range = ft_list_size(*stacka) / 2;
	i = (((grp - 1) * (ft_list_size(*stacka) / 4)) + 1);
	cursor = (*stacka)->next;
	while (cursor->dx != i && cursor)
	{
		cursor = cursor->next;
		hold++;
	}
	while ((*stacka)->next->dx != i)
	{
		if (hold <= range)
		{
			vstk(*stacka, *stackb, flags);
			caller(stacka, stackb, "ra");
		}
		else
		{
			vstk(*stacka, *stackb, flags);
			caller(stacka, stackb, "rra");
		}
	}
}

void	group_sort(t_body **stacka, t_body **stackb, t_flgs *flags, int grp)
{
	int		hold;
	int		range;
	int		max;
	t_body	*cursor;
	
	hold = 0;
	range = ft_list_size(*stackb) + 1;
	max = grp * ft_list_size(*stackb);
	cursor = (*stackb)->next;
	while ((*stackb)->next != NULL)
	{
		cursor = (*stackb)->next;
		hold = 0;
		range -= 1;
		max -= 1;
		if (!(*stackb)->next->next)
		{	
			vstk(*stacka, *stackb, flags);
			caller(stacka, stackb, "pa");
		}	
		else
		{
			while (cursor->dx != max)
			{
				cursor = cursor->next;
				hold++;
			}
			if (hold <= (range / 2))
			{
				while ((*stackb)->next->dx != max)
				{
					vstk(*stacka, *stackb, flags);
					caller(stacka, stackb, "rb");
				}
			}
			else if (hold > (range / 2))
			{
				while ((*stackb)->next->dx != max)
				{
					vstk(*stacka, *stackb, flags);
					caller(stacka, stackb, "rrb");
				}	
			}
			vstk(*stacka, *stackb, flags);
			caller(stacka, stackb, "pa");
		}
	}
}

void	final_sort(t_body **stacka, t_body **stackb, t_flgs *flags)
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
			{
				if (hold <= range)
				{
					caller(stacka, stackb, "ra");
					vstk(*stacka, *stackb, flags);
				}
				else
				{
					caller(stacka, stackb, "rra");
					vstk(*stacka, *stackb, flags);
				}
			}
		}
		else
		{
			cursor = cursor->next;
			i++;
		}
	}
}

void	call_sort(t_body **stacka, t_body **stackb, t_flgs *flags)
{
	int	grp;

	grp = 5;
	while (grp != 0)
	{
		group_push(stacka, stackb, grp, flags);
		if (grp == 5)
			sort_a(stacka, stackb, flags, 1);
		else
			sort_a(stacka, stackb, flags, (grp + 1));
		group_sort(stacka, stackb, flags, grp);
		grp--;
	}
	final_sort(stacka, stackb, flags);
	vstk(*stacka, *stackb, flags);
	printf("moves = %d\n", MOVES);
}