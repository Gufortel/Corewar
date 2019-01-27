/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:11:21 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/27 21:33:01 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int			pgdc(int limit)
{
	int		i;
	int		tmp;

	i = 2;
	while (i != MEM_SIZE / 2)
	{
		if (MEM_SIZE % i == 0 && i < limit)
			tmp = i;
		i++;
	}
	return (tmp);
}

void		colorwrite(int i, t_env *p, char **str)
{
	while (p->ptr)
	{
		if (p->ptr->die == 0)
		{
			if (p->ptr->pc == i && p->play[0]
			&& p->play[0]->nbdef == p->ptr->nbdef)
				ft_strcat(*str, "\033[1;41m");
			else if (p->ptr->pc == i && p->play[1]
			&& p->play[1]->nbdef == p->ptr->nbdef)
				ft_strcat(*str, "\033[1;44m");
			else if (p->ptr->pc == i && p->play[2]
			&& p->play[2]->nbdef == p->ptr->nbdef)
				ft_strcat(*str, "\033[1;42m");
			else if (p->ptr->pc == i && p->play[3]
			&& p->play[3]->nbdef == p->ptr->nbdef)
				ft_strcat(*str, "\033[1;43m");
			else if (p->ptr->pc == i && p->play[4]
			&& p->play[4]->nbdef == p->ptr->nbdef)
				ft_strcat(*str, "\033[1;46m");
			else if (p->ptr->pc == i && p->play[5]
			&& p->play[5]->nbdef == p->ptr->nbdef)
				ft_strcat(*str, "\033[1;45m");
		}
		p->ptr = p->ptr->next;
	}
}

void		color(int i, t_env *p, char **str, int *size)
{
	while (p->ptr)
	{
		*size = *size + 8;
		if (p->mp[i].players == 1)
			ft_strcat(*str, "\033[1;31m");
		else if (p->mp[i].players == 2)
			ft_strcat(*str, "\033[1;34m");
		else if (p->mp[i].players == 3)
			ft_strcat(*str, "\033[1;32m");
		else if (p->mp[i].players == 4)
			ft_strcat(*str, "\033[1;33m");
		else if (p->mp[i].players == 5)
			ft_strcat(*str, "\033[1;36m");
		else if (p->mp[i].players == 6)
			ft_strcat(*str, "\033[1;35m");
		else
			*size = *size - 8;
		p->ptr = p->ptr->next;
	}
}

void		dump_map(t_env *p)
{
	int		i;
	int		size;
	int		pgd;
	int		line;

	i = -1;
	size = 0;
	pgd = pgdc(70);
	line = 0;
	if (p->str == NULL)
		p->str = (char*)ft_memalloc(MEM_SIZE);
	ft_bzero(p->str, MEM_SIZE);
	vft_printf(&p->str, &size, "%#.4p : ", i + 1);
	while (++i < MEM_SIZE)
	{
		vft_printf(&p->str, &size, "%.2x ", p->mp[i].v);
		if ((i + 1) % pgd == 0 && i != 0)
		{
			vft_printf(&p->str, &size, "\n");
			if (i + 1 != MEM_SIZE)
				vft_printf(&p->str, &size, "%#.4x : ", i + 1);
		}
	}
	write(1, p->str, size);
}

void		dump_map_bonus(t_env *p)
{
	int		i;
	int		size;
	int		pgd;

	i = -1;
	size = 0;
	pgd = pgdc(70);
	if (p->str == NULL)
		p->str = (char*)ft_memalloc(MEM_SIZE);
	ft_bzero(p->str, MEM_SIZE);
	while (++i < MEM_SIZE)
	{
		p->ptr = p->begin;
		colorwrite(i, p, &p->str);
		ft_strcat(p->str, " \033[0;m");
		size = size + 14;
		p->ptr = p->begin;
		if (p->mp[i].v != 0)
			color(i, p, &p->str, &size);
		vft_printf(&p->str, &size, "%.2x\033[0;m", p->mp[i].v);
		if ((i + 1) % pgd == 0 && i != 0)
			vft_printf(&p->str, &size, "\n");
	}
	write(1, p->str, size);
}
