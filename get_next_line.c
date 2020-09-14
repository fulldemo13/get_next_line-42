/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulldemo <fulldemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 02:46:26 by fulldemo          #+#    #+#             */
/*   Updated: 2019/11/25 18:06:21 by fulldemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	new_line(char **s, char **line, int len)
{
	char	*tmp;

	if ((*s)[len] == '\n')
	{
		*line = ft_strndup(*s, len);
		tmp = ft_strndup(&((*s)[len + 1]), ft_strlen(&((*s)[len + 1])));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = *s;
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	check_line(char **s, char **line, int r)
{
	int		len;

	len = 0;
	if (r < 0)
		return (-1);
	else if (r == 0 && *s == NULL)
	{
		*line = ft_strndup("", 1);
		return (0);
	}
	else
	{
		while ((*s)[len] != '\n' && (*s)[len] != '\0')
			len++;
		return (new_line(s, line, len));
	}
}

int			get_next_line(const int fd, char **line)
{
	int			r;
	static char	*s[4096];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (*s == NULL)
			*s = ft_strndup(buff, ft_strlen(buff));
		else
		{
			tmp = ft_strjoin(*s, buff);
			free(*s);
			*s = tmp;
		}
		if (ft_strchr(*s, '\n'))
			break ;
	}
	return (check_line(s, line, r));
}
