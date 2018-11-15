/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:00:18 by gufortel          #+#    #+#             */
/*   Updated: 2018/11/15 21:09:01 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	testmagic(char *strr)
{
	unsigned char 	*str;
	int		i;

	i = COREWAR_EXEC_MAGIC;
	str = (unsigned char*)strr;
	//magic = (char*)ft_memalloc(sizeof(COREWAR_EXEC_MAGIC) + 1);
	//ft_strncpy(magic, str, sizeof(COREWAR_EXEC_MAGIC));
	if (str[0] == (i >> 24) && str[1] == ((i >> 16) & 0xff)
			&& str[2] == ((i >> 8) & 0xff) && str[3] == (i & 0xff))
		;
	else
		erreur("bad magic bit\n");
}

void	openfile(t_env *p)
{
	int		j;
	int		size;
	char	buf[PROG_NAME_LENGTH + COMMENT_LENGTH + sizeof(COREWAR_EXEC_MAGIC)];

	j = 0;
	size = PROG_NAME_LENGTH + COMMENT_LENGTH + sizeof(COREWAR_EXEC_MAGIC);
	while (p->play[j])
	{
		ft_printf("fichier a ouvrir : %s\n", p->play[j]->name_file);
		p->play[j]->fd = open(p->play[j]->name_file, O_RDONLY);
		if (p->play[j]->fd <= 0)
			erreur("%m\n");
		read(p->play[j]->fd, buf, size);
		testmagic(buf);
		ft_strncpy(p->play[j]->name, buf + sizeof(COREWAR_EXEC_MAGIC),
		PROG_NAME_LENGTH);
		ft_printf("name             = %s\n", p->play[j]->name);
		ft_strncpy(p->play[j]->comment, buf + (PROG_NAME_LENGTH +
		sizeof(COREWAR_EXEC_MAGIC) + 6), COMMENT_LENGTH);
		ft_printf("comment          = %s\n/////////////////////////////////////////////////\n", p->play[j]->comment);
		j++;
	}
}