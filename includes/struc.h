/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:25:57 by Gufortel          #+#    #+#             */
/*   Updated: 2019/02/12 20:46:22 by lmoreaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUC_H
# define STRUC_H

# define MAX_TAUNT (10 + (1 * 2))

typedef struct		s_op
{
	char			*name;
	int				nbarg;
	int				arg[4];
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
	int				nbdef; // position dans le tableau du champ + 1
	int				cycle; //
	int				live; //
	int				die;
	int				pos_cycle;
	struct s_proc	*next;
}					t_proc;

typedef struct		s_play
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char			taunt[102];
	unsigned char	champ[CHAMP_MAX_SIZE + 1];
	int				tnt; // position du char du taunt
	int				len_champ; // taille champion
	int				nb; //numero du champion accorde au lancement
	int				nbdef; //possition dans play + 1
	int				live; // 1 si live est execute
	int				fd; // le fd du fichiers
	int				adr; // aucune idee frere
	char			*name_file; // le nom du fichier pour faire le fd
}					t_play;

typedef struct		s_env
{
	t_play			*play[MAX_PLAYERS + 2];
	t_proc			*begin;
	t_map			mp[MEM_SIZE];
	t_proc			*ptr; //exclusivement pour dump a ne pas toucher !!
	t_op			*op_tab;
	char			*str; //buffer de dump
	int				cycle; //cycle actuel
	int				live; //nombre de live
	int				cycle_die; //cycle dans cycle to die
	int				cycle_act; // valeur de cycle pour verif
	int				check; // nombre de verif
	int				dump; // nombre de cycle max
	int				nbplayers; // nombre de joueurs
}					t_env;
#endif
