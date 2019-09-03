/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:22:43 by solivari          #+#    #+#             */
/*   Updated: 2019/09/03 10:28:40 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	maincall(t_body **stacka, t_body **stackb)
{
	int	size;

	size = ft_list_size(*stacka);
	if (size > 250)
		group(stacka, size);
	else
		agroup(stacka, size);
	if (size < 6)
		short_call(stacka, stackb);
	else if (checksort(*stacka, *stackb) == 0 && size > 250)
		call_sort(stacka, stackb);
	else if (checksort(*stacka, *stackb) == 0)
		call_sorta(stacka, stackb);
		
}

int		main(int argc, char **argv)
{
	int		j;
	t_body	*stacka;
	t_body	*stackb;
	t_flgs	*flags;

	j = 1;
	stacka = setmaster(&stacka, 0);
	stackb = setmaster(&stackb, 0);
	if (!(flags = (t_flgs *)malloc(sizeof(t_flgs))))
		erexit(&stacka, &stackb, &flags);
	if (argc > 1)
	{
		if (ft_rd((argv + 1), &stacka, &stackb, &flags) == 0)
			erexit(&stacka, &stackb, &flags);
		if (set_index(&stacka) < 0)
			erexit(&stacka, &stackb, &flags);
		maincall(&stacka, &stackb);
		// group(&stacka, ft_list_size(stacka));
		// if (ft_list_size(stacka) < 6)
		// 	short_call(&stacka, &stackb);
		// else if (checksort(stacka, stackb) == 0)
		// 	call_sort(&stacka, &stackb);
	}
	freestk(&stacka, &stackb);
	free(&(*flags));
	return (0);
}
