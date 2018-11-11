/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:51:18 by abossard          #+#    #+#             */
/*   Updated: 2018/07/05 09:08:36 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

char	*ft_decal(char *reste, int j)
{
	int				i;

	i = 0;
	while (reste[j] != '\0')
	{
		reste[i] = reste[j];
		i++;
		j++;
	}
	while (reste[i] != '\0')
		reste[i++] = '\0';
	return (reste);
}

int		get_next_line2(const int fd, char **line, char **reste, char *tmp)
{
	char			buf[BUFF_SIZE + 1];
	int				r_bytes;

	r_bytes = 0;
	buf[0] = '\0';
	while (!(ft_strchr(buf, '\n')))
	{
		r_bytes = read(fd, buf, BUFF_SIZE);
		buf[r_bytes] = '\0';
		*line = ft_strjoinfree(*line, buf, 1);
		if (r_bytes == 0 && **line == '\0')
			return (0);
		if (r_bytes == 0)
			break ;
	}
	if (*line)
	{
		if (!(tmp = ft_strchr(*line, '\n')))
			return (1);
		*reste = ft_strdup(tmp + 1);
		*tmp = '\0';
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			*tmp;
	static char		*reste[OPENMAX];

	tmp = NULL;
	if (fd < 0 || read(fd, 0x0, 0) == -1 || line == NULL || fd > OPENMAX)
		return (-1);
	*line = NULL;
	if (RESTE)
	{
		if ((tmp = ft_strchr(RESTE, '\n')))
		{
			*tmp = '\0';
			*line = ft_strdup(RESTE);
			RESTE = ft_decal(RESTE, tmp - RESTE + 1);
			return (1);
		}
		else
		{
			*line = ft_strdup(RESTE);
		}
	}
	return (get_next_line2(fd, line, &RESTE, tmp));
}
