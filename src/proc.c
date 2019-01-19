/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:55:00 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/19 18:44:11 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_proc		*createproc(void)
{
	t_proc *p;

	p = (t_proc *)ft_memalloc(sizeof(t_proc) * 2);
	if (!(p))
		exit(-42);
	return (p);
}

t_proc		*pushproc(t_proc **begin, int pc)
{
	t_proc *p;

	if (!(*begin))
	{
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

t_proc		*pushprocfirst(t_proc **begin, int pc)
{
	t_proc		*p;
	t_proc		*bef;

	if (!(*begin))
	{
		p = createproc();
		*begin = p;
	}
	else
	{
		bef = *begin;
		p = createproc();
		*begin = p;
		p->next = bef;
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
