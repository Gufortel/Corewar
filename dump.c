/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:11:21 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/05 19:16:45 by gufortel         ###   ########.fr       */
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

void		dump_map(t_env *p)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (p->mp[i].players == 1)
			ft_printf("{RED}");
		if (p->mp[i].players == 2)
			ft_printf("{BLUE}");
		if (p->mp[i].players == 3)
			ft_printf("{GREEN}");
		if (p->mp[i].players == 4)
			ft_printf("{YELLOW}");
		if (p->mp[i].players == 5)
			ft_printf("{PURPLE}");
		if (p->mp[i].players == 6)
			ft_printf("{CYAN}");
		if (p->mp[i].players == 0)
			ft_printf("{EOC}");
		ft_printf("%.2x {EOC}", p->mp[i].val);
		if (i % pgdc(MEM_SIZE, 70) == 0 && i != 0)
			ft_printf("\n");
		i++;
	}
}
