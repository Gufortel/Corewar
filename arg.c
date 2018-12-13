/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:16:30 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/13 18:08:15 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int			argint(t_env *p, int pc, int size)
{
	unsigned char arg[4];
	unsigned char argg[2];

	if (size == 2)
	{
		argg[0] = p->mp[pc + 1].v;
		argg[1] = p->mp[pc].v;
		return (*(short*)&argg[0]);
	}
	else
	{
		arg[0] = p->mp[pc + 3].v;
		arg[1] = p->mp[pc + 2].v;
		arg[2] = p->mp[pc + 1].v;
		arg[3] = p->mp[pc].v;
		return (*(int*)&arg[0]);
	}
	return (-1);
}