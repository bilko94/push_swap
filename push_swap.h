/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:59:01 by solivari          #+#    #+#             */
/*   Updated: 2019/08/12 17:06:03 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.a"
# define INT32_MAX 2147483647
# define INT32_MIN -2147483648
# define erexit {ft_putstr_fd("Error\n",2);exit(1);}
# define vstk(ta, tb, f) {if (f->v) {system("clear");\
                   ft_putendl("\nStack A\t\tStack B");\
                   vall(ta, tb);\
                   ft_putstr("\n\n");\
                   usleep(100000);}}

typedef struct		s_body
{
	int				master;
	int				value;
	struct s_body	*next;
	struct s_body	*prev;
}					t_body;

typedef struct		s_flgs
{
	int		v;
	int		c;
};					t_flgs;


t_body	*create_node(int value);
void	addnode(t_body **stack, int value);
t_body	*setmaster(t_body **stack, int	fv);
// void    printstacks(t_body **stacka, t_body **stackb);
void	checkflgs(char *argv, int argc, t_flgs **flags);
void	checkerror(int ac, char **av);
void	vall(t_body *ta, t_body *tb);
int		isdup(int ac, char **av)
void	sa(t_body **stacka);
void    sb(t_body **stackb);
void    ra(t_body **stacka);
void	rb(t_body **stackb);
void	rra(t_body **stacka);
void    rrb(t_body **stackb);
void	rr(t_body **stacka, t_body **stackb);
void	ss(t_body **stacka, t_body **stackb);
void	pa(t_body **stacka, t_body **stackb);
void	pb(t_body **stacka, t_body **stackb);
void    rrr(t_body **stacka, t_body **stackb);

#endif