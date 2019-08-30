/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:43 by solivari          #+#    #+#             */
/*   Updated: 2019/08/30 12:15:29 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int		ft_list_size(t_body *stacka)
// {
// 	int	i;

// 	i = -1;
// 	while (stacka)
// 	{
// 		i++;
// 		stacka = stacka->next;
// 	}
// 	return (i);
// }

int     main(int argc, char **argv)
{
    int		j;
	t_body	*stacka;
	t_body	*stackb;
	t_flgs	*flags;

	j = 1;
	stacka = setmaster(&stacka, 0);
	stackb = setmaster(&stackb, 0);
	if (!(flags = (t_flgs *)malloc(sizeof(t_flgs))))
		erexit;
	if (argc > 1)
	{
		if (ft_rd((argv + 1), stacka, flags) == 0)
			erexit;
		if (set_index(&stacka) < 0)
			erexit;
		group(&stacka, ft_list_size(stacka));
		if (checksort(stacka, stackb) == 1)
		{
			ft_putendl("\033[32mOK\033[00m");
			return (0);
		}
		call_sort(&stacka, &stackb);
	}
	checksort(stacka, stackb);
	return (0);
}

