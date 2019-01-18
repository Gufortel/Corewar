/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 22:35:52 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/17 17:32:41 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void		op_lfork(t_env *p, t_proc *c)
{
	int		pc;
	t_proc	*pt;

	pc = argint(p, c->pc + 1, 2);
//	ft_printf("fork a l'adresse %d\n", (c->pc + (pc % IDX_MOD)) % MEM_SIZE);
	pt = pushprocfirst(&p->begin, (c->pc + pc) % MEM_SIZE);
	pt->reg[1] = c->reg[1];
	pt->nbdef = c->nbdef;
	c->pc = (c->pc + 3) % MEM_SIZE;
}