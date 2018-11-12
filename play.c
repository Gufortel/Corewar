/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:32:03 by Gufortel          #+#    #+#             */
/*   Updated: 2018/11/12 20:55:42 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

t_play      *createplay(char *name, char *comment)
{
    t_play      *p;
    int         i;

    i = -1;
    p = (t_play*)ft_memalloc(sizeof(t_play) + 3);
    if (!(p))
        exit(-42);
    while (name[i++])
        p->name[i] = name[i];
    i = -1;
    while (comment[i++])
        p->comment[i] = comment[i];
    return (p);
}

void        delplay(t_play **pt)
{
    t_play  *p;

    p = *pt;
    if ()
}