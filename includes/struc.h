/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:25:57 by Gufortel          #+#    #+#             */
/*   Updated: 2019/01/09 15:20:00 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H

# define MAX_TAUNT (10 + (1 * 2))

typedef struct		s_op
{
	char			*name;
	int				nbarg;
	int				arg[3];
	int				op_code;
	int				cycles;
	char			*def;
	int				carry;
	int				jesaispas;
}					t_op;

typedef struct		s_map
{
	unsigned char			v;
	char					players;
}					t_map;

typedef struct		s_proc
{
	int				carry;
	int				pc;
	int				reg[REG_NUMBER + 1];
	int				nbdef;
	int				cycle;
	int				live;
	int				die;
	int				pos_cycle;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_play
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	unsigned char	champ[CHAMP_MAX_SIZE + 1];
	int				len_champ;
	int				nb;
	int				nbdef;
	int				live;
	int				fd;
	int				adr;
	char			*name_file;
	char			taunt[10 + (1 * 2)];
}					t_play;

typedef struct		s_env
{
	t_play			*play[MAX_PLAYERS + 1];
	t_proc			*begin;
	t_map			mp[MEM_SIZE];
	t_proc			*ptr; //exclusivement pour dump a ne pas toucher !!
	char			*str;
	int				proc;
	int				cycle;
	int				live;
	int				cycle_die;
	int				cycle_act;
	int				check;
	int				win;
	int				dump;
	int				nbplayers;
}					t_env;
#endif
