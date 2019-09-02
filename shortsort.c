/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:32:21 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 17:34:37 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertsort(t_body **stacka, t_body **stackb)
{
	int	size;

	size = ft_list_size(*stacka);
	while (size > 3)
	{
		if ((*stacka)->next->dx > 3)
		{
			acaller(stacka, stackb, "pb");
			size--;
		}
		else
			acaller(stacka, stackb, "ra");
	}
	hardsort(stacka, stackb);
	if ((*stackb)->next->next)
	{
		if ((*stackb)->next->dx < (*stackb)->next->next->dx)
			bcaller(stacka, stackb, "sb");
	}
	while ((*stackb)->next)
		bcaller(stacka, stackb, "pa");
	if (ft_list_size(*stacka) > 4)
		acaller(stacka, stackb, "ra");
	acaller(stacka, stackb, "ra");
}

void	bcaller(t_body **stacka, t_body **stackb, char *s)
{
	if (ft_strequ(s, "sb"))
	{
		write(1, "sb\n", 3);
		sb(stackb);
	}
	else if (ft_strequ(s, "rb"))
	{
		write(1, "rb\n", 3);
		rb(stackb);
	}
	else if (ft_strequ(s, "rrb"))
	{
		write(1, "rrb\n", 4);
		rrb(stackb);
	}
	else if (ft_strequ(s, "pa"))
	{
		write(1, "pa\n", 3);
		pa(stacka, stackb);
	}
}

void	acaller(t_body **stacka, t_body **stackb, char *s)
{
	if (ft_strequ(s, "sa"))
	{
		write(1, "sa\n", 3);
		sa(stacka);
	}
	else if (ft_strequ(s, "ra"))
	{
		write(1, "ra\n", 3);
		ra(stacka);
	}
	else if (ft_strequ(s, "rra"))
	{
		write(1, "rra\n", 4);
		rra(stacka);
	}
	else if (ft_strequ(s, "pb"))
	{
		write(1, "pb\n", 3);
		pb(stacka, stackb);
	}
}

void	hardsort(t_body **stacka, t_body **stackb)
{
	t_body	*firsta;
	t_body	*seconda;

	firsta = (*stacka)->next;
	seconda = firsta->next;
	if (falsechecksort(*stacka) == 0)
	{
		if (firsta->dx > seconda->dx)
		{
			if (firsta->dx == 3 && seconda->dx == 1)
				acaller(stacka, stackb, "ra");
			else
				acaller(stacka, stackb, "sa");
			seconda = (*stacka)->next->next;
			if ((*stacka)->next->dx == 2 && seconda->dx == 3)
				acaller(stacka, stackb, "rra");
		}
		else if (firsta->dx < seconda->dx)
		{
			acaller(stacka, stackb, "rra");
			if ((*stacka)->next->dx > (*stacka)->next->next->dx)
				acaller(stacka, stackb, "sa");
		}
	}
}

void	short_call(t_body **stacka, t_body **stackb)
{
	int	size;

	size = ft_list_size(*stacka);
	if (size <= 3)
		hardsort(stacka, stackb);
	else if (size <= 5)
		insertsort(stacka, stackb);
}
