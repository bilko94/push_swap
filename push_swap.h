/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 09:59:01 by solivari          #+#    #+#             */
/*   Updated: 2019/09/03 10:29:17 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

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
	int				v;
	int				c;
}					t_flgs;

typedef struct		s_var
{
	int				ret;
	int				j;
	int				fd;
	char			*line;
}					t_var;

void				erexit(t_body **stacka, t_body **stackb,\
					t_flgs **flags);
void				erexitc(t_body **stacka, t_body **stackb,\
					t_flgs **flags, t_var **var);
void				ifb(t_body **stacka, t_body **stackb,\
					int max, double range);
void				ifa(t_body **stacka, t_body **stackb,\
					double hold, double range);
void				vstk(t_body *stacka, t_body *stackb,\
					t_flgs *flags);
void				freecall(t_body **stacka,\
					t_body **stackb, t_flgs **flags, t_var **var);
void				group_sort(t_body **stacka,\
					t_body **stackb, int grp, double size);
int					ft_rd(char **av, t_body **stacka,\
					t_body **stackb, t_flgs **flags);
void				split(char *av, t_body **stacka,\
					t_body **stackb, t_flgs **flags);
void				check(t_body *stacka,\
					t_body *stackb, int moves, t_flgs *flags);
void				sort_a(t_body **stacka,\
					t_body **stackb, int grp, double size);
void				bestop(t_body **stacka, t_body **stackb,\
					int hold, int range);
void				agroup_sort(t_body **stacka, t_body **stackb,\
					int grp, double size);
void				asort_a(t_body **stacka, t_body **stackb,\
					int grp, double size);
void				group_push(t_body **stacka, t_body **stackb, int grp);
int					checkneg(char *av, t_body **stacka, t_flgs **flags);
void				acaller(t_body **stacka, t_body **stackb, char *s);
void				bcaller(t_body **stacka, t_body **stackb, char *s);
void				caller(t_body **stacka, t_body **stackb, char *s);
void				call_sorta(t_body **stacka, t_body **stackb);
void				final_sort(t_body **stacka, t_body **stackb);
void				insertsort(t_body **stacka, t_body **stackb);
void				short_call(t_body **stacka, t_body **stackb);
void				setgroup(t_body *stacka, int gp, int range);
void				vall(t_body *ta, t_body *tb, t_flgs *flags);
void				call_sort(t_body **stacka, t_body **stackb);
void				maincall(t_body **stacka, t_body **stackb);
void				hardsort(t_body **stacka, t_body **stackb);
int					checksort(t_body *stacka, t_body *stackb);
void				freestk(t_body **stacka, t_body **stackb);
void				freeme(t_body **stacka, t_body **stackb);
void				rrr(t_body **stacka, t_body **stackb);
void				rr(t_body **stacka, t_body **stackb);
void				ss(t_body **stacka, t_body **stackb);
void				pa(t_body **stacka, t_body **stackb);
void				pb(t_body **stacka, t_body **stackb);
void				agroup(t_body **stacka, double size);
void				group(t_body **stacka, double size);
int					checkflgs(char *str, t_flgs *flags);
t_body				*setmaster(t_body **stack, int	fv);
void				addnode(t_body **stack, int value);
int					sethold(t_body **stack, int max);
int					falsechecksort(t_body *stacka);
int					ft_list_size(t_body *stacka);
void				ifv(t_body *ta, t_body *tb);
int					set_index(t_body **stacka);
t_body				*create_node(int value);
int					validcheck(char *line);
void				printndx(t_body *stk);
int					checkerror(char *av);
void				rra(t_body **stacka);
void				rrb(t_body **stackb);
void				sa(t_body **stacka);
void				sb(t_body **stackb);
void				ra(t_body **stacka);
void				rb(t_body **stackb);
int					isdup(char **av);

#endif
