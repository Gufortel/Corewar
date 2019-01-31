/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_reg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:56:01 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/31 23:20:59 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	print_reg(t_env *p, t_proc *c, int adr, int val)
{
	int		i;

	i = 4;
	while (i--)
	{
		p->mp[((unsigned int)(c->pc + adr)) % MEM_SIZE].players = c->nbdef;
		p->mp[((unsigned int)(c->pc + adr)) % MEM_SIZE].v = val & 0xFF;
		val >>= 8;
		adr--;
	}
}
