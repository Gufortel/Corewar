/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:32:03 by Gufortel          #+#    #+#             */
/*   Updated: 2018/12/19 14:06:20 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

t_play		*createplay(char *name)
{
	t_play	*p;
	int		i;

	i = -1;
	p = (t_play *)ft_memalloc(sizeof(t_play) + 3);
	if (!(p))
		exit(-42);
	p->name_file = ft_strdup(name);
	return (p);
}

void		delplay(t_play **pt)
{
	t_play *p;

	p = *pt;
	if (p->name_file)
		ft_strdel(&p->name_file);
	free(p);
	pt = NULL;
}
