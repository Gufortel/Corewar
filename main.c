/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:15:46 by Gufortel          #+#    #+#             */
/*   Updated: 2018/11/13 16:33:57 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

t_play	*createplayers(char **av, int i, t_play *adr)
{
	if (!av[i + 1] || !av[i + 2])
		erreur("[[-n number] champion1.cor]\n");
	adr = createplay(av[i + 2]);
	adr->nb = (ft_atoi(av[i + 1]) > 0) ? ft_atoi(av[i + 1]) : 0;
	return (adr);
}

void	treat(char **av, t_env *p, int ac, int i)
{
	int		j;

	j = -1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0)
		{
			if (!av[i + 1] || ft_atoi(av[i + 1]) <= 0)
				erreur("[-dump nbr_cycles]\n");
			p->dump = ft_atoi(av[i + 1]);
			i++;
		}
		else if (ft_strcmp(av[i], "-n") == 0 && j++ > -12)
		{
			p->play[j] = createplayers(av, i, p->play[j]);
			p->play[j]->nb = (p->play[j]->nb == 0) ? j : p->play[j]->nb;
			i += 2;
		}
		else
		{
			p->play[j] = createplay(av[i]);
			p->play[j]->nb = j;
			j++;
		}
	}
}

int		main(int ac, char **av)
{
	t_env	*p;
	int		i;
	int		j;

	i = 1;
	j = 0;
	p = createenv();
	ft_printf("ac = %d\n", ac);
	treat(av, p, ac, 0);
	openfile(p);
	delenv(&p);
//	while (1);
}
