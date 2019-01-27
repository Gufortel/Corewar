/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:12:14 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/27 16:52:48 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		get_ind(int val, t_env *p, int pc, int bit)
{
	val = val % IDX_MOD;
	val = val % MEM_SIZE;
	return (argint(p, pc + val, bit));
}

int		get_ind_all(int val, t_env *p, int pc, int bit)
{
	val = val % MEM_SIZE;
	return (argint(p, pc + val, bit));
}
