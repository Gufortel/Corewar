/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:47:45 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/13 23:28:51 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

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
	else if (p->mp[ptr->pc].v == 11)
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

void	pos_cycle(t_env *p, t_proc *ptr)
{
	ft_printf("poscycle\n");
	ptr->pos_cycle = 1;
	if (p->mp[ptr->pc].v == 1)
		ptr->cycle = 9;
	else if (p->mp[ptr->pc].v == 2)
		ptr->cycle = 4;
	else if (p->mp[ptr->pc].v == 3)
		ptr->cycle = 4;
	else if (p->mp[ptr->pc].v == 4)
		ptr->cycle = 9;
	else if (p->mp[ptr->pc].v == 5)
		ptr->cycle = 9;
	else if (p->mp[ptr->pc].v == 6)
		ptr->cycle = 5;
	else if (p->mp[ptr->pc].v == 7)
		ptr->cycle = 5;
	else if (p->mp[ptr->pc].v == 8)
		ptr->cycle = 5;
	else if (p->mp[ptr->pc].v == 9)
		ptr->cycle = 19;
	else if (p->mp[ptr->pc].v == 10)
		ptr->cycle = 24;
	else if (p->mp[ptr->pc].v == 11)
		ptr->cycle = 24;
	else if (p->mp[ptr->pc].v == 12)
		ptr->cycle = 799;
	else if (p->mp[ptr->pc].v == 13)
		ptr->cycle = 9;
	else if (p->mp[ptr->pc].v == 14)
		ptr->cycle = 49;
	else if (p->mp[ptr->pc].v == 15)
		ptr->cycle = 999;
	else if (p->mp[ptr->pc].v == 16)
		ptr->cycle = 1;
}

void	loop(t_env *p)
{
	int		j;
	t_proc	*ptr;

	ft_printf("///////////debut traitement\\\\\\\\\\\\\\\\\\\\\\\\\n");
	ft_printf("p-dump = %d\n", p->dump);
	while ((p->cycle < p->dump && p->dump != 0) || p->dump == 0) 
	{
		ptr = p->begin;
		while (ptr)
		{
			//ft_printf("op code = %d\n", p->mp[ptr->pc].v);
			if (ptr->pos_cycle == 0 && ptr->die == 0)
				pos_cycle(p, ptr);
			if (ptr->cycle == 0 && ptr->die == 0)
				looploop(p, ptr);
			ptr->cycle = ptr->cycle - 1;
			ptr = ptr->next;
		}
		if (p->cycle_die == p->cycle_act && life(p) == 1)
			return;
		p->cycle = p->cycle + 1;
		p->cycle_die = p->cycle_die + 1;
		ft_printf("\\\\\\\\\\\\\\Cycle n'%d\n", p->cycle);
		//dump_map(p);
	}
	if (p->cycle == p->dump)
		dump_map(p);
}