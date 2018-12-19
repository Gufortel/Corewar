/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:08:03 by Gufortel          #+#    #+#             */
/*   Updated: 2018/12/19 14:45:30 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

t_env		*createenv(void)
{
	t_env *p;

	p = (t_env *)ft_memalloc(sizeof(t_env) + 2);
	if (!(p))
		exit(-42);
	p->cycle_act = CYCLE_TO_DIE;
	return (p);
}

void		delenv(t_env **p)
{
	int		i;
	t_env	*pt;

	i = 0;
	pt = *p;
	while (i < MAX_PLAYERS)
	{
		if (pt->play[i])
			delplay(&pt->play[i]);
		i++;
	}
	if (pt->begin)
		delproc(&pt->begin);
	free(pt);
	pt = NULL;
}
