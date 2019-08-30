/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:42:22 by solivari          #+#    #+#             */
/*   Updated: 2019/08/30 19:56:26 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	erexit(t_body **stacka, t_body **stackb, t_flgs **flags)
{
	ft_putstr_fd("\033[31mError invalid input\n\033[31m", 2);
	freestk(stacka, stackb);
	free(*flags);
	exit(1);
}

void	erexitc(t_body **stacka, t_body **stackb, t_flgs **flags, t_var **var)
{
	ft_putstr_fd("\033[31mError invalid input\n\033[31m", 2);
	freecaller(stacka, stackb, flags, var);
	exit(1);
}

void	vstk(t_body *stacka, t_body *stackb, t_flgs *flags)
{
	if ((*flags).v == 1)
	{
		system("clear");
		ft_putendl("\033[01;37m\nStack A\t\tStack B\033[01;37m");
		vall(stacka, stackb);
		ft_putstr("\n\n");
		usleep(10000);
	}
}
