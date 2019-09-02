/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 19:42:22 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 17:31:27 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	erexit(t_body **stacka, t_body **stackb, t_flgs **flags)
{
	ft_putstr_fd("\033[31mError invalid input\n\033[31m", 2);
	freestk(stacka, stackb);
	free(*flags);
	exit(1);
}

void	erexitc(t_body **stacka, t_body **stackb, t_flgs **flags, t_var **var)
{
	ft_putstr_fd("\033[31mError invalid input\n\033[31m", 2);
	freecall(stacka, stackb, flags, var);
	exit(1);
}

int		checkneg(char *av, t_body **stacka, t_flgs **flags)
{
	if (checkflgs(av, *flags) == 0)
	{
		if (checkerror(&av[1]) == 0)
			return (0);
		addnode(stacka, ft_atoi(av));
	}
	return (1);
}
