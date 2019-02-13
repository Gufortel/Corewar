# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gufortel <gufortel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 19:51:44 by gufortel          #+#    #+#              #
#    Updated: 2019/02/13 17:36:54 by lmoreaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar_

SRC = src/add.c\
	src/and.c\
	src/arg.c\
	src/create_proc.c\
	src/dump.c\
	src/env.c\
	src/erreur.c\
	src/fd.c\
	src/fork.c\
	src/get_all.c\
	src/get_arg.c\
	src/get_ind.c\
	src/ld.c\
	src/ldi.c\
	src/lfork.c\
	src/life.c\
	src/live.c\
	src/lld.c\
	src/lldi.c\
	src/loadchamp.c\
	src/loop.c\
	src/main.c\
	src/op.c\
	src/openfile.c\
	src/or.c\
	src/play.c\
	src/proc.c\
	src/st.c\
	src/sti.c\
	src/sub.c\
	src/xor.c\
	src/zjmp.c\
	src/print_reg.c\
	src/aff.c\

OBJ = src/add.o\
	src/and.o\
	src/arg.o\
	src/create_proc.o\
	src/dump.o\
	src/env.o\
	src/erreur.o\
	src/fd.o\
	src/fork.o\
	src/get_all.o\
	src/get_arg.o\
	src/get_ind.o\
	src/ld.o\
	src/ldi.o\
	src/lfork.o\
	src/life.o\
	src/live.o\
	src/lld.o\
	src/lldi.o\
	src/loadchamp.o\
	src/loop.o\
	src/main.o\
	src/op.o\
	src/openfile.o\
	src/or.o\
	src/play.o\
	src/proc.o\
	src/st.o\
	src/sti.o\
	src/sub.o\
	src/xor.o\
	src/zjmp.o\
	src/print_reg.o\
	src/aff.o\

all: $(NAME)

$(OBJ): $(SRC) ./includes/corewar.h ./includes/op.h ./includes/proto.h ./includes/struc.h 
	@gcc -Wall -Wextra -Werror -c -O3 $(SRC)
	@mv *.o ./src/

$(NAME): $(OBJ)
	@make -C ./libft/
	@gcc -o $(NAME) $(OBJ) -Wall -Wextra -Werror ./libft/libft.a

clean:
	@rm -Rf $(OBJ)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all

.PHONY: clean fclean all re
