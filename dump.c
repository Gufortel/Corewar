/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:11:21 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/09 20:06:28 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

int			pgdc(int nb, int limit)
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

void		colorwrite(int i, t_env *p, char **str, int *size)
{
	while (p->ptr)
	{
		*size = *size + 8;
		if (p->ptr->pc == i && p->play[0]->nb == p->ptr->reg[1]
		&& p->ptr->die == 0)
			ft_strcat(*str, "\033[1;41m");
		else if (p->ptr->pc == i && p->play[1]->nb == p->ptr->reg[1]
		&& p->ptr->die == 0)
			ft_strcat(*str, "\033[1;44m");
		else if (p->ptr->pc == i && p->play[2]->nb == p->ptr->reg[1]
		&& p->ptr->die == 0)
			ft_strcat(*str, "\033[1;42m");
		else if (p->ptr->pc == i && p->play[3]->nb == p->ptr->reg[1]
		&& p->ptr->die == 0)
			ft_strcat(*str, "\033[1;43m");
		else if (p->ptr->pc == i && p->play[4]->nb == p->ptr->reg[1]
		&& p->ptr->die == 0)
			ft_strcat(*str, "\033[1;46m");
		else if (p->ptr->pc == i && p->play[5]->nb == p->ptr->reg[1]
		&& p->ptr->die == 0)
			ft_strcat(*str, "\033[1;45m");
		else if (p->ptr->pc == i && p->play[0]->nb == p->ptr->reg[1]
		&& p->ptr->die == 0)
		{
			ft_strcat(*str, "\033[0;m");
			*size = *size - 2;
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

	i = -1;
	size = 0;
	if (p->str == NULL)
		p->str = (char*)ft_memalloc(MEM_SIZE);
	ft_bzero(p->str, MEM_SIZE);
	//vft_printf(&p->str, &size, "{CLEAR}\n");
	while (++i < MEM_SIZE)
	{
		p->ptr = p->begin;
		colorwrite(i, p, &p->str, &size);
		ft_strcat(p->str, " \033[0;m");
		size = size + 6;
		p->ptr = p->begin;
		color(i, p, &p->str, &size);
		vft_printf(&p->str, &size, "%.2x", p->mp[i].v);
		ft_strcat(p->str, "\033[0;m");
		size = size + 6;
		if ((i + 1) % pgdc(MEM_SIZE, 70) == 0 && i != 0)
			vft_printf(&p->str, &size, "\n");
	}
	vft_printf(&p->str, &size, "\n\n");
	write(1, p->str, size);
}
