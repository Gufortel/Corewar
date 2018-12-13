/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:17:34 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/08 17:00:25 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int		get_00(int x)
{
	return ((x & 0b11000000) >> 6);
}

int		get_01(int x)
{
	return ((x & 0b110000) >> 4);
}

int		get_02(int x)
{
	return ((x & 0b1100) >> 2);
}

int		get_03(int x)
{
	return ((x & 0b11));
}