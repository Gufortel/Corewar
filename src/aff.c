/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:40:07 by lmoreaux          #+#    #+#             */
/*   Updated: 2019/02/12 22:20:59 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	aff(t_env *p, t_proc *c)
{
	int	j;

	j = 0;
	while (j < p->nbplayers && c->reg[1] != p->play[j]->nb)
		j++;
	if (get_00(p->mp[c->pc + 1].v) == 1)
	{
		if (p->play[j]->tnt == 0)
			ft_bzero(p->play[j]->taunt, 101);
		if (c->reg[p->mp[c->pc + 2].v] % 256 == 0)
			c->carry = 1;
		aff2(p, c, j);
	}
	c->pc = c->pc + 3;
}

void	aff2(t_env *p, t_proc *c, int j)
{
	if (c->reg[p->mp[c->pc + 2].v] % 256 != 0 && c->carry != 1)
	{
		p->play[j]->taunt[p->play[j]->tnt] = c->reg[p->mp[c->pc + 2].v] % 256;
		p->play[j]->tnt = p->play[j]->tnt + 1;
	}
	if (p->play[j]->tnt == 99 || c->carry == 1)
	{
		if (j >= p->nbplayers)
			ft_printf("\nUn fantome murmure : ");
		ft_printf(p->play[j]->taunt);
		ft_putchar('\n');
		p->play[j]->tnt = 0;
	}
}
