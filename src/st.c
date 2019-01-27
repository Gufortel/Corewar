/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:23:01 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/27 19:08:51 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	st(t_env *p, t_proc *c)
{
	int		reg;

	if ((get_01(p->mp[c->pc + 1].v) == 1 || get_01(p->mp[c->pc + 1].v)
	== 3) && get_00(p->mp[c->pc + 1].v) == 1)
	{
		if (get_01(p->mp[c->pc + 1].v) == 1 && p->mp[c->pc + 3].v >= 1
		&& p->mp[c->pc + 3].v <= REG_NUMBER)
		{
			c->reg[p->mp[c->pc + 3].v] = c->reg[p->mp[c->pc + 2].v];
		}
		else if (get_01(p->mp[c->pc + 1].v) == 3)
		{
			reg = argint(p, c->pc + 3, 2);
			print_reg(p, c, ((reg) % IDX_MOD) + 3, c->reg[p->mp[c->pc + 2].v]);
		}
	}
	c->pc = c->pc + (4 + ((p->mp[c->pc + 1].v & 0x20) >> 5));
}
