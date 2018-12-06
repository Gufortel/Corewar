/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:55:00 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/06 23:14:14 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

t_proc		*createproc(void)
{
	t_proc *p;

	p = (t_proc *)ft_memalloc(sizeof(t_proc) + 3 + 1);
	if (!(p))
		exit(-42);
	return (p);
}

t_proc		*pushproc(t_proc **begin, int pc)
{
	t_proc *p;

	if (!(*begin))
	{
		ft_printf("baise base\n");
		p = createproc();
		*begin = p;
	}
	else
	{
		p = *begin;
		while (p->next)
			p = p->next;
		p->next = createproc();
		p = p->next;
	}
	p->pc = pc;
	return (p);
}

void		delproc(t_proc **begin)
{
	t_proc *p;
	t_proc *tmp;

	if (!(*begin))
		return ;
	p = *begin;
	while (p)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	*begin = NULL;
}
