/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:25:19 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/09 20:35:15 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int		get_all(t_env *p, int type, t_proc *c, int nbarg)
{
	if (type == 1)
		return (c->reg[p->mp[c->pc + nbarg + 1].v]);
	else if (type == 2)
		return (argint(p, c->pc + 1 + nbarg, 4));
	else if (type == 3)
		return (get_ind(p->mp[c->pc + nbarg + 1].v, p, c->pc, 2));
	return (-42);
}