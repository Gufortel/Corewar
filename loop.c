/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:47:45 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/06 23:53:24 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	loop(t_env *p)
{
	int		j;
	t_proc	*ptr;

	ft_printf("///////////debut traitement\\\\\\\\\\\\\\\\\\\\\\\\\n");
	ptr = p->begin;
	while (ptr)
	{
		if (p->mp[ptr->pc].val == 1)
			live(p, ptr);
		ptr = ptr->next;
		p->cycle = p->cycle + 1;
		dump_map(p);
	}
}