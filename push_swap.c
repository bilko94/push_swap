/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:43 by solivari          #+#    #+#             */
/*   Updated: 2019/07/18 16:03:45 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    int		i;
	t_body	*cursor;
	t_body	*stacka;
	t_body	*stackb;

	i = 1;
	stacka = setmaster(&stacka, 0);
	cursor = stacka;
	stackb = setmaster(&stackb, 0);
	if (argc > 1)
	{
		while (i < argc)
		{
			addnode(&stacka, ft_atoi(argv[i++]));
		}
	}
	pa(&stacka, &stackb);
	ft_putstr("stacka	stackb\n");
	while (cursor)
	{
		printf("%d	%d\n", cursor->value, stackb->value);
		// printf("master = %d	%d\n", stacka->master, stackb->master);
		cursor = cursor->next;
		stacka = stacka->next;
		if (stackb->next != NULL)
			stackb = stackb->next;
	}
	// printf("stacka = %d\n", stacka->value);
	// cleanup(&stacka, &stackb);
	return (0);
}

