/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:27:44 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/31 23:21:36 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int			or2(t_env *p, t_proc *c)
{
	int		tmp;

	tmp = 0;
	tmp = (get_01(p->mp[c->pc + 1].v) == 1) ? tmp + 1 : tmp;
	tmp = (get_00(p->mp[c->pc + 1].v) == 1) ? tmp + 1 : tmp;
	tmp = (get_00(p->mp[c->pc + 1].v) == 2) ? tmp + 4 : tmp;
	tmp = (get_01(p->mp[c->pc + 1].v) == 2) ? tmp + 4 : tmp;
	tmp = (get_00(p->mp[c->pc + 1].v) == 3) ? tmp + 2 : tmp;
	tmp = (get_01(p->mp[c->pc + 1].v) == 3) ? tmp + 2 : tmp;
	return (tmp);
}

void		or(t_env *p, t_proc *c)
{
	int		tmp;
	int		tt;

	tt = 0;
	if ((get_00(p->mp[c->pc + 1].v) == 1 || get_00(p->mp[c->pc + 1].v) == 2
	|| get_00(p->mp[c->pc + 1].v) == 3) && (get_01(p->mp[c->pc + 1].v) == 1
	|| get_01(p->mp[c->pc + 1].v) == 2 || get_01(p->mp[c->pc + 1].v) == 3)
	&& (get_02(p->mp[c->pc + 1].v) == 1))
	{
		tt = (get_00(p->mp[c->pc + 1].v) == 1) ? 2 : tt;
		tt = (get_00(p->mp[c->pc + 1].v) == 2) ? 5 : tt;
		tt = (get_00(p->mp[c->pc + 1].v) == 3) ? 3 : tt;
		tmp = get_all(p, get_00(p->mp[c->pc + 1].v), c, 1)
		| get_all(p, get_01(p->mp[c->pc + 1].v), c, tt);
		c->reg[p->mp[c->pc + 4].v] = tmp;
		c->carry = ((get_00(p->mp[c->pc + 1].v) == 1 && p->mp[c->pc + 2].v >= 1
		&& p->mp[c->pc + 2].v <= REG_NUMBER) || get_00(p->mp[c->pc + 1].v) !=
		1) ? 1 : 0;
		c->carry = (tmp == 0) ? 1 : 0;
	}
	c->pc = c->pc + 3 + or2(p, c);
}
