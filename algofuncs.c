/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algofuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 20:31:55 by solivari          #+#    #+#             */
/*   Updated: 2019/08/30 20:42:16 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bestop(t_body **stacka, t_body **stackb, int hold, int range)
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

void	ifb(t_body **stacka, t_body **stackb, int max, double range)
{
	int		hold;

	hold = sethold(stackb, max);
	if (hold <= (range / 2))
	{
		while ((*stackb)->next->dx != max)
		{
			write(1, "rb\n", 3);
			caller(stacka, stackb, "rb");
		}
	}
	else if (hold > (range / 2))
	{
		while ((*stackb)->next->dx != max)
		{
			write(1, "rrb\n", 4);
			caller(stacka, stackb, "rrb");
		}
	}
}
