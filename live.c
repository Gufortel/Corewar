/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:29:21 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/07 17:54:18 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	live(t_env *p, t_proc *ptr)
{
	int		live;
	int		j;

	j = 0;
	live = argint(p, ptr->pc + 1, 4);
	p->live = p->live + 1;
	while (p->play[j]->nb != live && j < MAX_PLAYERS)
		j++;
	if (j != MAX_PLAYERS)
	{
		p->play[j]->live = 1;
		ft_printf("un processus dit que le joueur %d(%s) est en vie)\n",
		p->play[j]->nb, p->play[j]->name);
		ft_printf("j = %d\n", j);
	}
	ptr->pc = ptr->pc + 5;
}