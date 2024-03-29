/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:08:00 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 17:30:42 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkops(t_body **stacka, t_body **stackb, char **line)
{
	if (ft_strequ(*line, "sa"))
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

int		runwhile(t_body **stacka, t_body **stackb, t_flgs **flags, t_var **var)
{
	int	moves;

	moves = 0;
	while (((*var)->ret = get_next_line((*var)->fd, &(*var)->line)) > 0)
	{
		checkops(stacka, stackb, &(*var)->line);
		ft_putendl((*var)->line);
		if (validcheck((*var)->line) == 1)
			moves++;
		else if (validcheck((*var)->line) == 0)
			erexitc(stacka, stackb, flags, var);
		vstk((*stacka)->next, (*stackb)->next, (*flags));
		if (checksort(*stacka, *stackb) == 1)
			break ;
	}
	return (moves);
}

t_var	*initialize(void)
{
	t_var	*new;

	if (!(new = (t_var *)malloc(sizeof(t_var) + 1)))
		return (NULL);
	new->fd = 0;
	new->j = 1;
	new->line = malloc(1);
	new->ret = 0;
	return (new);
}

void	check(t_body *stacka, t_body *stackb, int moves, t_flgs *flags)
{
	if (checksort(stacka, stackb) == 1 && flags->c == 1)
		ft_putendl("\033[32mOK!\n\033[00m");
	else if (checksort(stacka, stackb) == 1 && flags->c != 1)
		ft_putendl("OK!\n");
	if (checksort(stacka, stackb) == 0 && flags->c == 1)
		ft_putendl("\033[32mKO!\n\033[00m");
	else if (checksort(stacka, stackb) == 0 && flags->c != 1)
		ft_putendl("KO!\n");
	if (flags->c == 1)
		ft_putstr("\033[33mMoves = \033[33m");
	else
		ft_putstr("Moves = ");
	ft_putendl(ft_itoa(moves));
}

int		main(int argc, char **argv)
{
	t_var	*var;
	t_body	*stacka;
	t_body	*stackb;
	t_flgs	*flags;
	int		moves;

	moves = 0;
	var = initialize();
	stacka = setmaster(&stacka, 0);
	stackb = setmaster(&stackb, 0);
	if (!(flags = (t_flgs *)malloc(sizeof(t_flgs))))
		erexitc(&stacka, &stackb, &flags, &var);
	if (argc > 1)
	{
		if (ft_rd((argv + 1), &stacka, &stackb, &flags) == 0)
			erexitc(&stacka, &stackb, &flags, &var);
		vstk(stacka->next, stackb->next, flags);
		moves = runwhile(&stacka, &stackb, &flags, &var);
	}
	check(stacka, stackb, moves, flags);
	freecall(&stacka, &stackb, &flags, &var);
	return (0);
}
