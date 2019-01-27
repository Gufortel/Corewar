/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:46:10 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/27 19:17:14 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		op_fork(t_env *p, t_proc *c)
{
	int		pc;
	int		i;
	t_proc	*pt;

	i = 0;
	pc = argint(p, c->pc + 1, 2);
	pt = pushprocfirst(&p->begin, (c->pc + (pc % IDX_MOD)) % MEM_SIZE);
	while (++i <= REG_NUMBER)
		pt->reg[i] = c->reg[i];
	pt->nbdef = c->nbdef;
	pt->carry = c->carry;
	c->pc = (c->pc + 3) % MEM_SIZE;
}
