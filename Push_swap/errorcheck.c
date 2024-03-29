/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:52:06 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 17:16:29 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		isdup(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (j != i && ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		checkerror(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (!(ft_isdigit(av[i++])))
			return (0);
	}
	if (ft_atol(av) > INT32_MAX)
		return (0);
	return (1);
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

void	split(char *av, t_body **stacka, t_body **stackb, t_flgs **flags)
{
	int		j;
	char	**split;

	j = 0;
	split = ft_strsplit(av, ' ');
	if (ft_rd(split, stacka, stackb, flags) == 0)
		erexit(stacka, stackb, flags);
	while (split[j])
		free(split[j++]);
	free(split);
}

int		ft_rd(char **av, t_body **stacka, t_body **stackb, t_flgs **flags)
{
	int	i;

	i = -1;
	while (av[++i] != '\0')
	{
		if (ft_strchr(av[i], ' '))
			split(av[i], stacka, stackb, flags);
		else if (av[i][0] == '-')
		{
			if (checkneg(av[i], stacka, flags) == 0)
				return (0);
		}
		else
		{
			if (checkerror(av[i]) == 0)
				return (0);
			if (isdup(av) == 0)
				return (0);
			addnode(stacka, ft_atoi(av[i]));
		}
	}
	return (1);
}
