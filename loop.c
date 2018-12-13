/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:47:45 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/13 18:59:44 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	looploop(t_env *p, t_proc *ptr)
{
	if (p->mp[ptr->pc].v == 1)
		live(p, ptr);
	else if (p->mp[ptr->pc].v == 2)
		ld(p, ptr);
}

void	loop(t_env *p)
{
	int		j;
	t_proc	*ptr;

	ft_printf("///////////debut traitement\\\\\\\\\\\\\\\\\\\\\\\\\n");
	ft_printf("p-dump = %d\n", p->dump);
	while (p->cycle < p->dump || p->cycle != 3)
	{
		ptr = p->begin;
		while (ptr)
		{
			looploop(p, ptr);
			ptr = ptr->next;
		}
		p->cycle = p->cycle + 1;
		p->cycle_die = p->cycle_die + 1;
		dump_map(p);
	}
}