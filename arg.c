/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:16:30 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/06 23:23:38 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int			argint(t_env *p, int pc, int size)
{
	unsigned char arg[4];

	arg[0] = 0;
	arg[1] = 0;
	arg[2] = 0;
	arg[3] = 0;
	if (size == 2)
	{
		arg[0] = p->mp[pc + 1].val;
		arg[1] = p->mp[pc].val;
	}
	else
	{
		arg[0] = p->mp[pc + 3].val;
		arg[1] = p->mp[pc + 2].val;
		arg[2] = p->mp[pc + 1].val;
		arg[3] = p->mp[pc].val;
	}
	return (*(int*)&arg[0]);
}