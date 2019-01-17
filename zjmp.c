/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:12:42 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/14 19:42:53 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	zjmp(t_env *p, t_proc *c)
{
	int		tmp;

	tmp = argint(p, c->pc + 1, 2);
	tmp = tmp % IDX_MOD;
	c->pc = (c->carry == 1) ? (c->pc + tmp) % MEM_SIZE : (c->pc + 3) % MEM_SIZE;
}