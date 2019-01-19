/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:35:21 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/19 19:23:35 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	winchamp(t_env *p)
{
	int		j;
	int		best;
	int		tmp;

	j = 0;
	best = p->play[j]->live;
	tmp = 0;
	while (j < p->nbplayers && p->play[j])
	{
		if (p->play[j]->live > best)
		{
			best = p->play[j]->live;
			tmp = j;
		}
		j++;
	}
	ft_printf("Le joueur %d(%s) a gagne\n",
	p->play[tmp]->nb, p->play[tmp]->name);
}

int		life(t_env *p)
{
	t_proc	*ptr;

	if (p->live >= NBR_LIVE)
	{
		p->cycle_act = p->cycle_act - CYCLE_DELTA;
		p->live = 0;
	}
	else
		p->check = p->check + 1;
	if (p->check == MAX_CHECKS)
	{
		p->cycle_act = p->cycle_act - CYCLE_DELTA;
		p->check = 0;
	}
	ptr = p->begin;
	while (ptr)
	{
		if (ptr->live == 1)
			ptr->live = 0;
		else
			ptr->die = 1;
		ptr = ptr->next;
	}
	p->cycle_die = 0;
	return (1);
}
