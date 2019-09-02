/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solivari <solivari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:48:57 by solivari          #+#    #+#             */
/*   Updated: 2019/09/02 17:39:34 by solivari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_nextline(char **str, char **line, int fd, int ret)
{
	char	*tmp;
	int		length;

	length = 0;
	while (str[fd][length] != '\n' && str[fd][length] != '\0')
		length++;
	if (str[fd][length] == '\n')
	{
		*line = ft_strsub(str[fd], 0, length);
		tmp = ft_strdup(str[fd] + (length + 1));
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][length] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[200];
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	int				ret;

	if ((line == NULL) || (fd < 0) || (ret = read(fd, NULL, 0) < 0))
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if ((ret == 0 && str[fd] == NULL) || str[fd][0] == '\0')
		return (0);
	return (ft_nextline(str, line, fd, ret));
}
