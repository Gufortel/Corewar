/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:47:45 by gufortel          #+#    #+#             */
/*   Updated: 2019/02/12 20:55:13 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	looploop2(t_env *p, t_proc *ptr)
{
	if (p->mp[ptr->pc].v == 11)
		sti(p, ptr);
	else if (p->mp[ptr->pc].v == 12)
		op_fork(p, ptr);
	else if (p->mp[ptr->pc].v == 13)
		lld(p, ptr);
	else if (p->mp[ptr->pc].v == 14)
		lldi(p, ptr);
	else if (p->mp[ptr->pc].v == 15)
		op_lfork(p, ptr);
	else if (p->mp[ptr->pc].v == 16)
		aff(p, ptr);
}

void	looploop(t_env *p, t_proc *ptr)
{
	ptr->pos_cycle = 0;
	if (p->mp[ptr->pc].v == 1)
		live(p, ptr);
	else if (p->mp[ptr->pc].v == 2)
		ld(p, ptr);
	else if (p->mp[ptr->pc].v == 3)
		st(p, ptr);
	else if (p->mp[ptr->pc].v == 4)
		add(p, ptr);
	else if (p->mp[ptr->pc].v == 5)
		sub(p, ptr);
	else if (p->mp[ptr->pc].v == 6)
		and(p, ptr);
	else if (p->mp[ptr->pc].v == 7)
		or(p, ptr);
	else if (p->mp[ptr->pc].v == 8)
		xor(p, ptr);
	else if (p->mp[ptr->pc].v == 9)
		zjmp(p, ptr);
	else if (p->mp[ptr->pc].v == 10)
		ldi(p, ptr);
	else
		looploop2(p, ptr);
}

void	pos_cycle(t_env *p, t_proc *ptr)
{
	ptr->pos_cycle = 1;
	ptr->cycle = (p->op_tab[(p->mp[ptr->pc].v) - 1].cycles) - 1;
}

void	loop(t_env *p, int i, t_proc *ptr)
{
	while ((p->cycle < p->dump && p->dump != 0) || p->dump == 0)
	{
		ptr = p->begin;
		i = 0;
		while (ptr)
		{
			i = (ptr->die == 0) ? i + 1 : i;
			if (ptr->pos_cycle == 0 && ptr->die == 0)
				pos_cycle(p, ptr);
			if (ptr->cycle == 0 && ptr->die == 0)
				looploop(p, ptr);
			ptr->cycle = ptr->cycle - 1;
			ptr = ptr->next;
		}
		if (i == 0)
			break ;
		if (p->cycle_die == p->cycle_act)
			life(p);
		p->cycle = p->cycle + 1;
		p->cycle_die = p->cycle_die + 1;
		clean_proc(&p->begin);
	}
	(p->cycle == p->dump) ? dump_map_bonus(p) : winchamp(p);
}
