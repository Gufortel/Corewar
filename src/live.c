/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:29:21 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/31 23:31:28 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	live(t_env *p, t_proc *ptr)
{
	int		live;
	int		j;

	j = 0;
	live = argint(p, ptr->pc + 1, 4);
	p->live = p->live + 1;
	while (j < p->nbplayers && p->play[j]->nb != live)
		j++;
	if (j < p->nbplayers)
	{
		p->play[j]->live = p->cycle;
		ft_printf("un processus dit que le joueur %d(%s) est en vie !\n",
		p->play[j]->nb, p->play[j]->name, live);
	}
	else
		ft_printf("un processus dit qu'un joueur inconnu est en vie(debile)\n");
	ptr->live = 1;
	ptr->pc = ptr->pc + 5;
	ptr->pc = ptr->pc % MEM_SIZE;
}
