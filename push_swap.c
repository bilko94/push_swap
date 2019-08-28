/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:43 by solivari          #+#    #+#             */
/*   Updated: 2019/08/28 15:37:26 by solivari         ###   ########.fr       */
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

// void	insertsort(t_body **stacka, t_body **stackb, t_flgs *flags)
// {
// 	t_body	*current;
// 	t_body	*insertion;
// 	int		count;
// 	int 	i;
	
// 	i = 0;
// 	count = 0;
// 	while (checksort(*stacka, *stackb, flags) == 0)
// 	{
// 		i = 1;
// 		while (i < ft_list_size(*stacka))
// 		{
// 			insertion = (*stacka)->next;
// 			current = (*stacka)->next->next;
// 			if (insertion->value > current->value)
// 			{
// 				sa(stacka);
// 				count++;
// 			}
// 			ra(stacka);
// 			count++;
// 			i++;
// 			vstk(*stacka, *stackb, flags);
// 		}
// 		ra(stacka);
// 		count++;
// 		vstk(*stacka, *stackb, flags);
// 	}
// 	printf("count = %d\n", count);
// }

int     main(int argc, char **argv)
{
    int		j;
	t_body	*cursor;
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
		call_sort(&stacka, &stackb, flags);
		// insertsort(&stacka, &stackb, flags);
	}
	checksort(stacka, stackb, flags);
	return (0);
}

