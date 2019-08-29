/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:59:01 by solivari          #+#    #+#             */
/*   Updated: 2019/08/29 15:55:20 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define erexit {ft_putstr_fd("Error\n",2);exit(1);}
# define vstk(ta, tb, f) {if (f->v == 1) {/*system("clear");*/\
                   ft_putendl("\nStack A\t\tStack B");\
                   vall(ta, tb);\
                   ft_putstr("\n\n");\
                   usleep(10000);}}

typedef struct		s_body
{
	int				master;
	int				value;
	int				dx;
	int				gp;
	struct s_body	*next;
	struct s_body	*prev;
	
}					t_body;

typedef struct		s_flgs
{
	int		v;
	int		c;
}					t_flgs;


void	group_push(t_body **stacka, t_body **stackb, int grp, t_flgs *flags);
void	sort_a(t_body **stacka, t_body **stackb, t_flgs *flags, int grp, int size);
void	insertsort(t_body **stacka, t_body **stackb, t_flgs *flags);
void	group_sort(t_body **stacka, t_body **stackb, t_flgs *flags, int grp, int size);
void	final_sort(t_body **stacka, t_body **stackb, t_flgs *flags);
void	call_sort(t_body **stacka, t_body **stackb, t_flgs *flags);
void	checksort(t_body *stacka, t_body *stackb, t_flgs *flags);
void	caller(t_body **stacka, t_body **stackb, char *s);
int		ft_rd(char **av, t_body *stacka, t_flgs *flags);
void	setgroup(t_body *stacka, int gp, int range);
int		checkflgs(char *str, t_flgs *flags);
t_body	*setmaster(t_body **stack, int	fv);
void	addnode(t_body **stack, int value);
void	group(t_body **stacka, double size);
void	vall(t_body *ta, t_body *tb);
int		ft_list_size(t_body *stacka);
int		set_index(t_body **stacka);
t_body	*create_node(int value);
void	printndx(t_body *stk);
int		checkerror(char *av);
int		isdup(char **av);
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