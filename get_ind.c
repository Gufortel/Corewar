/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:12:14 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/09 13:30:20 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int		get_ind(int val, t_env *p, int pc, int bit)
{
	val = val % IDX_MOD;
	return (argint(p, pc + val, bit));
}