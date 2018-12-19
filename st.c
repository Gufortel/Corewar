/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:23:01 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/19 19:06:03 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	st(t_env *p, t_proc *c)
{
	int		reg;

	if ((get_01(p->mp[c->pc + 1].v) == 1 || get_01(p->mp[c->pc + 1].v)
	==	 3) && get_00(p->mp[c->pc + 1].v) == 1)
	{
		if (get_01(p->mp[c->pc + 1].v) == 1 && p->mp[c->pc + 3].v >= 1
		&& p->mp[c->pc + 3].v <= REG_NUMBER)
		{
			c->reg[p->mp[c->pc + 3].v] = c->reg[p->mp[c->pc + 2].v];
		}
		else if (get_01(p->mp[c->pc + 1].v) == 3)
		{
			reg = argint(p, c->pc + 3, 2);
			p->mp[c->pc + (reg % IDX_MOD)].v = c->reg[p->mp[c->pc + 2].v];
			p->mp[c->pc + (reg % IDX_MOD)].players = c->nbdef;
		}
	}
	ft_printf("reg 1 = %d\n", c->reg[1]);
	c->pc = c->pc + (4 + ((p->mp[c->pc + 1].v & 0x20) >> 5));
}
