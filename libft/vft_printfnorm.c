/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfnorm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 08:42:35 by gufortel          #+#    #+#             */
/*   Updated: 2018/03/17 05:58:00 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int		vprintbuffer(t_var *ptr, char **str, int *nbr)
{
	char	*buffer;
	t_var	*p;
	int		i;
	int		tmp;

	p = ptr;
	i = 0;
	buffer = ft_memalloc(g_len + 2);
	while (p)
	{
		ft_strcat(buffer + i, p->str);
		i = i + ft_strlen(p->str);
		if (p->s == 42)
		{
			tmp = i - ft_strlen(p->str);
			buffer[chroccu(buffer)] = '\0';
		}
		p = p->next;
	}
	*nbr = g_len;
	*str = buffer;
	del_t_var(&ptr);
	g_nbvar = 0;
	return (g_len);
}
