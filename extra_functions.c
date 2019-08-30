/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fuctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:49:02 by solivari          #+#    #+#             */
/*   Updated: 2019/08/30 13:54:23 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_list_size(t_body *stacka)
{
	int	i;

	i = -1;
	while (stacka)
	{
		i++;
		stacka = stacka->next;
	}
	return (i);
}

int		validcheck(char *line)
{
	if (!ft_strequ(line, "sb") && !ft_strequ(line, "sa") &&\
		!ft_strequ(line, "ss") && !ft_strequ(line, "pa") &&\
		!ft_strequ(line, "pb") && !ft_strequ(line, "ra") &&\
		!ft_strequ(line, "rb") && !ft_strequ(line, "rr") &&\
		!ft_strequ(line, "rra") && !ft_strequ(line, "rrb") &&\
		!ft_strequ(line, "rrr"))
		return (0);
	return (1);
}