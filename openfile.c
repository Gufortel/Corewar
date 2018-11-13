/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:00:18 by gufortel          #+#    #+#             */
/*   Updated: 2018/11/13 16:46:25 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar.h"

void	openfile(t_env	*p)
{
	int		j;
	int		size;
	char	buf[PROG_NAME_LENGTH + COMMENT_LENGTH + sizeof(COREWAR_EXEC_MAGIC)];

	j = 0;
	size = PROG_NAME_LENGTH + COMMENT_LENGTH + sizeof(COREWAR_EXEC_MAGIC);
	ft_printf("size = %d\n", size);
	while (p->play[j])
	{
		ft_printf("fichier a ouvrir : %s\n", p->play[j]->name_file);
		p->play[j]->fd = open(p->play[j]->name_file, O_RDONLY);
		if (p->play[j]->fd <= 0)
			erreur("%m\n");
		read(p->play[j]->fd, buf, size);
		ft_printf("text = %s\n", buf);
		ft_strncpy(p->play[j]->name, buf + sizeof(COREWAR_EXEC_MAGIC),
		PROG_NAME_LENGTH);
		ft_printf("name    = %s\n", p->play[j]->name);
		ft_strncpy(p->play[j]->comment, buf + (PROG_NAME_LENGTH +
		sizeof(COREWAR_EXEC_MAGIC)), COMMENT_LENGTH);
		ft_printf("comment = %s taille debut = %d\n\n", p->play[j]->comment, (PROG_NAME_LENGTH +
		sizeof(COREWAR_EXEC_MAGIC)));
		j++;
	}
}