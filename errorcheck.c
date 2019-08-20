/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:52:06 by solivari          #+#    #+#             */
/*   Updated: 2019/08/20 12:32:03 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		isdup(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i != ac)
	{
		j = i + 1;
		while (j != ac)
		{
			if (j != i && ft_strcmp(av[i], av[j]) == 0)
				erexit;
			j++;
		}
		i++;
	}
}

void		checkerror(char *av)
{
	int i;

	i = 0;
	while (av[i] != '\0')
	{
		if ((!(ft_isdigit(av[i++]))))
			erexit;
	}
	if (ft_atol(av) > INT32_MAX)
		erexit;
}

int		checkflgs(char *str, t_flgs *flags)
{
    if (ft_strcmp(str, "-v") == 0)
	{
		flags->v = 1;
		return (1);
	}
	if (ft_strcmp(str, "-c") == 0)
	{
		flags->c = 1;
		return (1);
	}
return (0);
}

void    ft_rd(char **av, int ac, t_body *stacka, t_flgs *flags)
{
    int i;
    int j;
    
    i = 1;
    j = 0;
	if (ft_strchr(*av, ' '))
		ft_rd(ft_strsplit(av[i], ' '), ac, stacka, flags);
    isdup(ac, av);
    while (i < ac)
    {
        if (av[i][j] == '-')
        {
            if (checkflgs(av[i], flags) == 0)
            {
                checkerror(av[i]);
                addnode(&stacka, ft_atoi(av[i]));
            }
        }
        else
        {
            checkerror(av[i]);
            addnode(&stacka, ft_atoi(av[i]));
        }
        i++;
    }
}