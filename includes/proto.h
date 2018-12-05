/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:19:16 by Gufortel          #+#    #+#             */
/*   Updated: 2018/12/05 14:45:05 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

/*
** parse.c
*/

void	parsename(void);

/*
** op.c
*/

t_op	*buildtab(t_op *pt);

/*
** env.c
*/

t_env	*createenv(void);
void	delenv(t_env **p);

/*
** play.c
*/

t_play	*createplay(char *name);
void	delplay(t_play **p);

/*
** proc.c
*/

t_proc	*createproc(void);
t_proc	*pushproc(t_proc **begin, int pc);
void	delproc(t_proc **begin);

/*
** erreur.c
*/

void	erreur(char *str);

/*
** openfile.c
*/

void	openfile(t_env *p);

/*
** loadchamp.c
*/

void	loadchamp(t_play *p);

/*
** fd.c
*/

int		fd_open(char *name, int i);
int		fd_close(int fd);

/*
** dump.c
*/

void	dump_map(t_env *p);

/*
** 
*/
#endif
