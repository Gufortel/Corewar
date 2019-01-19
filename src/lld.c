/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 22:21:56 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/19 19:03:01 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	lld(t_env *p, t_proc *c)
{
	int		val;

	val = 0;
	c->reg[2] = 0;
	if ((get_00(p->mp[c->pc + 1].v) == 2 || get_00(p->mp[c->pc + 1].v)
	== 3) && get_01(p->mp[c->pc + 1].v) == 1)
	{
		if ((p->mp[c->pc + 6 - (((p->mp[c->pc + 1].v) & 0x60) >> 5)].v >= 1)
		&& (p->mp[c->pc + 6 - (((p->mp[c->pc + 1].v) & 0x60) >> 5)].v <=
		REG_NUMBER))
		{
			val = (get_00(p->mp[c->pc + 1].v) == 2) ? argint(p, c->pc + 2, 4)
			: get_ind_all(argint(p, c->pc + 2, 2), p, c->pc, 4);
			c->reg[p->mp[c->pc + 6 - (((p->mp[c->pc + 1].v) & 0x60) >> 5)]
			.v] = val;
			c->carry = (val == 0) ? 0 : 1;
		}
	}
	c->pc = c->pc + 7 - (((p->mp[c->pc + 1].v) & 0x60) >> 5);
}
