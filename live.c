/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:29:21 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/13 23:15:10 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	live(t_env *p, t_proc *ptr)
{
	int		live;
	int		j;

	j = 0;
	ft_printf("live\n");
	live = argint(p, ptr->pc + 1, 4);
	p->live = p->live + 1;
	while (j < p->nbplayers && p->play[j]->nb != live)
		j++;
	if (j < p->nbplayers)
	{
		p->play[j]->live = p->cycle;
		ft_printf("un processus dit que le joueur %d(%s) est en vie)\n",
		p->play[j]->nb, p->play[j]->name);
		ft_printf("j = %d\n", j);
	}
	ptr->live = 1;
	ptr->pc = ptr->pc + 5;
	ptr->pc = ptr->pc % MEM_SIZE;
}
