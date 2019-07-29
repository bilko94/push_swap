/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:43 by solivari          #+#    #+#             */
/*   Updated: 2019/07/29 15:31:34 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    int		j;
	t_body	*cursor;
	t_body	*stacka;
	t_body	*stackb;

	j = 1;
	stacka = setmaster(&stacka, 0);
	stackb = setmaster(&stackb, 0);

	if (argc > 1)
	{
		while (j < argc)
			addnode(&stacka, ft_atoi(argv[j++]));
	}
	ft_putstr("stacka	stackb\n");
	printstacks(&stacka, &stackb);
	return (0);
}

