/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 08:18:59 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/05 17:23:10 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int			fd_open(char *name, int i)
{
	int		fd;

	fd = open(name, i);
	if (fd == -1)
		erreur("%m\n");
	return (fd);
}

int			fd_close(int fd)
{
	int		i;

	i = close(fd);
	if (i == -1)
		erreur("%m\n");
	return (i);
}
