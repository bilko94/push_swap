/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:08:00 by solivari          #+#    #+#             */
/*   Updated: 2019/08/05 16:36:18 by solivari         ###   ########.fr       */
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
	else if (ft_strequ(*line, "rb"))
		rb(stackb);
	else if (ft_strequ(*line, "rr"))
		rr(stacka, stackb);
	else if (ft_strequ(*line, "rra"))
		rra(stacka);
	else if (ft_strequ(*line, "rrb"))
		rrb(stackb);
	else if (ft_strequ(*line, "rrr"))
		rrr(stacka, stackb);
}

int			isdup(int ac, char **av)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		checkerror(int ac, char **av)
{
	int i;
	int j;

	j = 1;
	while (j != ac)
	{
		i = 0;
		while (av[j][i] != '\0')
		{
			if (!(ft_isdigit(av[j][i++])))
				erexit;
		}
		if (ft_atol[j] > INT32_MAX)
			erexit;
		j++;
	}
	if (isdup(ac, av))
		erexit;
}

void		checkflgs(char *argv, int argc, t_flgs **flags)
{
	int i;

	i = 1;
	while (argc > 0)
	{
		if (ft_strcmp(argv[i], "-v") == 0)
			flags->v = 1;
		else
			flags->v = 0;
		if (ft_strcmp(argv[i++], "-c") == 0)
			flags->c = 1;
		else
			flags->c = 0;
		argc--;
	}
}

int     	main(int argc, char **argv)
{
	int     ret;
	int		j;
	int     fd;
	char    *line;
	t_body	*stacka;
	t_body	*stackb;
	t_flgs	*flags;
	
	j = 1;
	stacka = setmaster(&stacka, 0);
	stackb = setmaster(&stackb, 0);
	checkflgs(argv, argc, &flags);
	if (argc > 1)
	{
		checkerror(argc, argv);
		while (j < argc)
			addnode(&stacka, ft_atoi(argv[j++]));
		fd = 0;
		line = malloc(1);
		while ((ret = get_next_line(fd,&line))> 0)
		{
			checkops(&stacka, &stackb, &line);
			ft_putendl(line);
			ft_putchar('\n');
			if (flags->v == 1)
				vstk(stacka, stackb, flgs);
			// printstacks(&stacka, &stackb);
		}
	}
	free(line);
	return (0);
}