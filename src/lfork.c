/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 22:35:52 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/27 19:17:17 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		op_lfork(t_env *p, t_proc *c)
{
	int		pc;
	int		i;
	t_proc	*pt;

	i = 0;
	pc = argint(p, c->pc + 1, 2);
	pt = pushprocfirst(&p->begin, (c->pc + pc) % MEM_SIZE);
	while (++i <= REG_NUMBER)
		pt->reg[i] = c->reg[i];
	pt->nbdef = c->nbdef;
	pt->carry = c->carry;
	c->pc = (c->pc + 3) % MEM_SIZE;
}
