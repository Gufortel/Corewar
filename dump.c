/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:11:21 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/13 18:03:26 by gufortel         ###   ########.fr       */
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
		if (p->ptr->pc == i && p->play[0]->nb == p->ptr->reg[0])
			vft_printf(str, size, "{B_RED}");
		else if (p->ptr->pc == i && p->play[1]->nb == p->ptr->reg[0])
			vft_printf(str, size, "{B_BLUE}");
		else if (p->ptr->pc == i && p->play[2]->nb == p->ptr->reg[0])
			vft_printf(str, size, "{B_GREEN}");
		else if (p->ptr->pc == i && p->play[3]->nb == p->ptr->reg[0])
			vft_printf(str, size, "{B_YELLOW}");
		else if (p->ptr->pc == i && p->play[4]->nb == p->ptr->reg[0])
			vft_printf(str, size, "{B_CYAN}");
		else if (p->ptr->pc == i && p->play[5]->nb == p->ptr->reg[0])
			vft_printf(str, size, "{B_PURPLE}");
		else if (p->ptr->pc == i && p->play[0]->nb == p->ptr->reg[0])
			vft_printf(str, size, "{EOC}");
		p->ptr = p->ptr->next;
	}
}

void		color(int i, t_env *p, char **str, int *size)
{
	while (p->ptr)
	{
		if (p->mp[i].players == 1)
			vft_printf(str, size, "{RED}");
		else if (p->mp[i].players == 2)
			vft_printf(str, size, "{BLUE}");
		else if (p->mp[i].players == 3)
			vft_printf(str, size, "{GREEN}");
		else if (p->mp[i].players == 4)
			vft_printf(str, size, "{YELLOW}");
		else if (p->mp[i].players == 5)
			vft_printf(str, size, "{CYAN}");
		else if (p->mp[i].players == 6)
			vft_printf(str, size, "{PURPLE}");
		p->ptr = p->ptr->next;
	}
}

void		dump_map(t_env *p)
{
	int		i;
	char	*str;
	int		size;

	i = -1;
	size = 0;
	str = (char*)ft_memalloc(MEM_SIZE / 4);
//	vft_printf(&str, &size, "{CLEAR}\n");
	while (++i < MEM_SIZE)
	{
		p->ptr = p->begin;
		colorwrite(i, p, &str, &size);
		vft_printf(&str, &size, " {EOC}", p->mp[i].v);
		p->ptr = p->begin;
		color(i, p, &str, &size);
		vft_printf(&str, &size, "%.2x{EOC}", p->mp[i].v);
		if ((i + 1) % pgdc(MEM_SIZE, 70) == 0 && i != 0)
			vft_printf(&str, &size, "\n");
	}
	vft_printf(&str, &size, "\n\n");
	write(1, str, size);
	ft_strdel(&str);
}
