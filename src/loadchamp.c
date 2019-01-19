/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadchamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:46:07 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/19 18:40:06 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	loadchamp(t_play *p)
{
	char	test[14];
	int		i;

	i = 0;
	read(p->fd, test, 12);
	while (read(p->fd, test, 1) > 0)
	{
		p->champ[i] = test[0];
		if ((i) >= CHAMP_MAX_SIZE)
		{
			ft_printf("Champ : %s, is too big! Size max is %d",
			p->name, CHAMP_MAX_SIZE);
			erreur("\n");
		}
		i++;
	}
	p->len_champ = i;
}
