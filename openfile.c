/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:00:18 by gufortel          #+#    #+#             */
/*   Updated: 2018/12/13 18:44:50 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	testmagic(char *strr)
{
	unsigned char	*str;
	int				i;

	i = COREWAR_EXEC_MAGIC;
	str = (unsigned char*)strr;
	if (str[0] == (i >> 24) && str[1] == ((i >> 16) & 0xff)
			&& str[2] == ((i >> 8) & 0xff) && str[3] == (i & 0xff))
		;
	else
		erreur("bad magic bit\n");
}

void	check_nb(t_env *p, int ch, int i, int j)
{
	while (ch != 0)
	{
		ch = 0;
		j = MAX_PLAYERS - 1;
		while (j >= 0)
		{
			i = MAX_PLAYERS - 1;
			while (i >= 0)
			{
				if (p->play[i] && p->play[j] && p->play[i]->nb == p->play[j]->nb
				&& i != j && ++ch != -12)
				{
					if (p->play[j]->nbdef == 1)
						p->play[j]->nb = p->play[j]->nb + 1;
					else if (p->play[i]->nbdef == 1)
						p->play[i]->nb = p->play[i]->nb + 1;
					else
						erreur("number must be different\n");
				}
				i--;
			}
			j--;
		}
	}
}

void	init_arena(t_env *p)
{
	int		pos;
	int		j;
	int		i;

	pos = 0;
	j = 0;
	check_nb(p, 1, MAX_PLAYERS - 1, MAX_PLAYERS - 1);
	while (p->play[j])
	{
		p->play[j]->adr = pos;
		i = 0;
		ft_printf("joueur %d = %d\n", j, p->play[j]->nb);
		while (i < CHAMP_MAX_SIZE)
		{
			p->mp[pos].v = p->play[j]->champ[i];
			p->mp[pos].players = (p->play[j]->champ[i] != 0) ?
			j + 1 : 0;
			i++;
			pos++;
		}
		j++;
		pos = j * MEM_SIZE / p->nbplayers;
	}
	create_proc(p);
}

void	openfile(t_env *p)
{
	int		j;
	int		size;
	char	buf[sizeof(t_header)];

	j = 0;
	size = PROG_NAME_LENGTH + COMMENT_LENGTH + sizeof(COREWAR_EXEC_MAGIC);
	while (p->play[j])
	{
		if (j > MAX_PLAYERS)
			erreur("Nombre de players incorrecte\n");
		ft_printf("fichier a ouvrir : %s\n", p->play[j]->name_file);
		p->play[j]->fd = fd_open(p->play[j]->name_file, O_RDONLY);
		read(p->play[j]->fd, buf, size);
		testmagic(buf);
		ft_strncpy(p->play[j]->name, buf + sizeof(COREWAR_EXEC_MAGIC),
		PROG_NAME_LENGTH);
		ft_printf("name             = %s\n", p->play[j]->name);
		ft_strncpy(p->play[j]->comment, buf + (PROG_NAME_LENGTH +
		sizeof(COREWAR_EXEC_MAGIC) + 6), COMMENT_LENGTH);
		ft_printf("comment          = %s\n/////////////////////////////////////////////////\n", p->play[j]->comment);
		loadchamp(p->play[j]);
		fd_close(p->play[j]->fd);
		j++;
	}
	p->nbplayers = j;
	ft_printf("nombre de joeurs = %d\n", j);
	init_arena(p);
}
