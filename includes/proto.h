/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:19:16 by Gufortel          #+#    #+#             */
/*   Updated: 2018/11/12 17:46:17 by Gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

t_op	*buildtab(t_op *pt);
t_env   *createenv(void);
void    delenv(t_env **p);
t_play  *createplay(char *name, char *comment);
void    parsename(void);

#endif
