/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:08:00 by solivari          #+#    #+#             */
/*   Updated: 2019/07/18 16:53:06 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    checkops(t_body **stacka, t_body **stackb, char **line)
{
    if(ft_strequ(*line, "sa"))
        sa(stacka);
    else if (ft_strequ(*line, "sb"))
        sb(stackb);
    else if (ft_strequ(*line, "ss"))
        ss(stacka, stackb);
    else if (ft_strequ(*line, "pa"))
        pa(stacka, stackb);
    else if (ft_strequ(*line, "pb"))
        pb(stacka, stackb);
    else if (ft_strequ(*line, "ra"))
        ra(stacka);
    // else if (ft_strequ(*line, "rb"))
    //     rb(stackb);
    // else if (ft_strequ(*line, "rr"))
    //     rr(stacka, stackb);
    // else if (ft_strequ(*line, "rra"))
    //     rra(stacka);
    // else if (ft_strequ(*line, "rrb"))
    //     rrb(stackb);
    // else if (ft_strequ(*line, "rrr"))
    //     rrr(stacka, stackb);
}

int     main(int argc, char **argv)
{
    int     ret;
    int		j;
    int     fd;
    char    *line;
	t_body	*stacka;
	t_body	*stackb;

	j = 1;
	stacka = setmaster(&stacka, 0);
	stackb = setmaster(&stackb, 0);
		if (argc > 1)
	{
		while (j < argc)
		{
			addnode(&stacka, ft_atoi(argv[j++]));
		}
	}
    fd = 0;
    line = malloc(1);
    while ((ret = get_next_line(fd,&line))> 0)
    {
        checkops(&stacka, &stackb, &line);
        ft_putendl(line);
        ft_putchar('\n');
        printstacks(&stacka, &stackb);
    }
    free(line);
    return (0);
}