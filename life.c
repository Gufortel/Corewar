/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:35:21 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/20 15:31:38 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	winchamp(t_env *p)
{
	int		j;
	int		best;
	int		tmp;

	j = 0;
	best = p->play[j]->live;
	while (j < MAX_PLAYERS && p->play[j])
	{
		if (p->play[j]->live > best)
		{
			best = p->play[j]->live;
			tmp = j;
		}
	}
	ft_printf("Le joueur %d(%s) a gagne\n", p->play[j]->nb, p->play[j]->name);
}

int		win(t_env *p)
{
	int		i;
	t_proc	*ptr;

	i = 0;
	ptr = p->begin;
	while (ptr)
	{
		if (ptr->die == 0)
			i++;
		ptr = ptr->next;
	}
	if (i != 0)
		return (0);
	else
	{
		winchamp(p);
		return (1);
	}
}

int		life(t_env *p)
{
	int		j;
	int		i;
	t_proc	*ptr;

	j = -1;
	i = 0;
	if (p->live >= NBR_LIVE)
		p->cycle_act = p->cycle_act - CYCLE_DELTA;
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
		if (ptr->live == 1 && ptr->die == 0)
			ptr->live = 0;
		else
			ptr->die = 1;
		ptr = ptr->next;
	}
	p->cycle_die = 0;
	return (win(p));
}
