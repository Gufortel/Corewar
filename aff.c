/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:26:19 by gufortel          #+#    #+#             */
/*   Updated: 2019/01/14 15:29:44 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/corewar.h"

void		aff(t_env *p, t_proc *c)
{
	int		aff;
	char	s;
	char	add[2];

	if (get_00(p->mp[c->pc + 1].v) == 1)
	{
		aff = c->reg[p->mp[c->pc + 2].v];
		s = (char)(aff % 256);
		add[0] = s;
		add[1] = '\0';
 		if (s == 0)
		{
			ft_printf("un joueur dit : %s\n", c->taunt);
			ft_bzero(c->taunt, 12);
		}
		else
			ft_strcat(c->taunt, add);
		c->pc = c->pc + 3;
	}
}
