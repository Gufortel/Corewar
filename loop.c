/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:47:45 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/09 17:19:16 by gufortel         ###   ########.fr       */
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
			if (ptr->pos_cycle == 0 && ptr->die == 0)
				pos_cycle(p, ptr);
			if (ptr->cycle == 0 && ptr->die == 0)
				looploop(p, ptr);
			ptr->cycle = ptr->cycle - 1;
			ptr = ptr->next;
		}
		if (p->cycle_die == p->cycle_act && life(p) == 1)
			break;
		p->cycle = p->cycle + 1;
		p->cycle_die = p->cycle_die + 1;
		ft_printf("\\\\\\\\\\\\\\Cycle n'%d\n", p->cycle);
		dump_map(p);
	}
	if (p->cycle == p->dump)
		dump_map(p);
}