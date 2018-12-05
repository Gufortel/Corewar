/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadchamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:46:07 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/05 09:05:31 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	loadchamp(t_play *p)
{
	char	test[10];
	int		i;

	i = 0;
	while (read(p->fd, test, 1) > 0)
	{
		p->champ[i] = test[0];
		if ((i) >= CHAMP_MAX_SIZE)
			erreur("CHAMP to big\n");
		i++;
	}
	p->len_champ = i;
	ft_printf("champ = '%s'\n\n", p->champ);
}