/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 13:06:56 by solivari          #+#    #+#             */
/*   Updated: 2019/06/12 14:56:09 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		j;
	char	*str;

	str = s;
	j = -1;
	if (s && f)
	{
		while (s[++j])
			f(&str[j]);
	}
}