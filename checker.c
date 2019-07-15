/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:08:00 by solivari          #+#    #+#             */
/*   Updated: 2019/07/15 15:39:29 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void    checkops(t_body *stacka, t_body *stackb, char *line)
// {
//     if(ft_strequ(line, "sa"))
//          sa();
// }

int     main()
{
    int     i;
    int     fd;
    char    **line;

    fd = 0;
    i = 1;
    line = malloc(1);
    *line = malloc(1);
    while ((i = get_next_line(fd,line))> 0)
    {
        // checkops(&line);
        ft_putendl(*line);
        ft_putchar('\n');
    }
    // checkops(&line);
    return (0);
}