/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:49:02 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 17:30:29 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sethold(t_body **stack, int max)
{
	int		hold;
	t_body	*cursor;

	hold = 0;
	cursor = (*stack)->next;
	while (cursor->dx != max)
	{
		cursor = cursor->next;
		hold++;
	}
	return (hold);
}

void	freestk(t_body **stacka, t_body **stackb)
{
	t_body	*cursor;
	t_body	*cursor1;

	cursor = (*stacka);
	cursor1 = cursor->next;
	while (cursor->next)
	{
		cursor = cursor1;
		free(cursor);
		cursor1 = cursor1->next;
	}
	free(*stacka);
	cursor = (*stackb);
	cursor1 = cursor->next;
	while (cursor->next)
	{
		cursor = cursor1;
		free(cursor);
		cursor1 = cursor1->next;
	}
	free(*stackb);
}

void	freecall(t_body **stacka, t_body **stackb, t_flgs **flags, t_var **var)
{
	freestk(stacka, stackb);
	free(*flags);
	free(*var);
}

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
