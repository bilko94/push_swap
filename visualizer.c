/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:39:08 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 17:39:59 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vstk(t_body *stacka, t_body *stackb, t_flgs *flags)
{
	if ((*flags).v == 1)
	{
		system("clear");
		if (flags->c == 1)
			ft_putendl("\033[01;37m\nStack A\t\tStack B\033[01;37m");
		else
			ft_putendl("\nStack A\t\tStack B");
		vall(stacka, stackb, flags);
		ft_putstr("\n\n");
		usleep(100000);
	}
}

void	ifv(t_body *ta, t_body *tb)
{
	if (ta != NULL && tb != NULL)
	{
		ft_putstr(ft_itoa(ta->value));
		ft_putstr("\t\t");
		ft_putendl(ft_itoa(tb->value));
	}
	else if (ta != NULL && tb == NULL)
	{
		ft_putstr(ft_itoa(ta->value));
		ft_putendl("\t\t-");
	}
	else if (ta == NULL && tb != NULL)
	{
		ft_putstr("-\t\t");
		ft_putendl(ft_itoa(tb->value));
	}
}

void	vall(t_body *ta, t_body *tb, t_flgs *flags)
{
	if (flags->c == 1)
		ft_putstr("\033[22;32m");
	while (ta || tb)
	{
		ifv(ta, tb);
		if (ta != NULL && tb != NULL)
		{
			ta = ta->next;
			tb = tb->next;
		}
		else if (ta != NULL && tb == NULL)
			ta = ta->next;
		else if (ta == NULL && tb != NULL)
			tb = tb->next;
	}
	ft_putstr("\033[22;39m");
}
