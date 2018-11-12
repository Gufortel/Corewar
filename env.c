/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:08:03 by Gufortel          #+#    #+#             */
/*   Updated: 2018/11/12 18:00:23 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

t_env       *createenv(void)
{
    t_env   *p;

    p = (t_env*)ft_memalloc(sizeof(t_env) + 2);
    if (!(p))
        exit(-42);
    return (p);
}

void        delenv(t_env **p)
{
    int     i;
    t_env   *pt;

    i = 0;
    pt = *p;
    while (i++ < MAX_PLAYERS)
   //     delplay(&pt->name[i]);
    if (pt->begin)
        free(pt->begin);
    free(pt);
    p = NULL;
}