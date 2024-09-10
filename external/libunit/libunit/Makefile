# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/04 21:12:50 by tlegrand          #+#    #+#              #
#    Updated: 2024/09/08 14:43:09 by tlegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##
# libunit
#
# @file Makefile
# @version 0.2


#	==============================	NAME	==============================	#
NAME	=	libunit.a

#	==============================	CMP	==============================	#
AR			=	ar
ARFLAG		=	rcs

CC			=	gcc 
CFLAG		=	-Wall -Wextra -Werror -g3 
DFLAG		=	-MMD -MP


#	==============================	INCLUDE	==============================	#
DIR_INC		=	inc/
IFLAG		=	-I ${DIR_INC}


#	==============================	SRC	==============================	#
SRC_DIR		=	src/
SRC_LST		=	test_loader.c test_launcher.c
SRC			=	${addprefix ${SRC_DIR}, ${SRC_LST}}


#	==============================	OBJ	==============================	#
OBJ_DIR		=	.obj/
OBJ_LST		=	${SRC_LST:.c=.o}
OBJ			=	${addprefix ${OBJ_DIR}, ${OBJ_LST}}



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY: all clean fclean
#	==============================	BASE	==============================	#
all: ${OBJ_DIR} ${NAME}

clean:
	@rm -rf ${OBJ_DIR}
	@echo "Clean"

fclean: clean
	@rm -f ${NAME}
	@echo "FClean"

re: fclean all


#	==============================	COMPILATION	==============================	#
${NAME}: ${OBJ_DIR} ${OBJ}
	${AR} ${ARFLAG} $@ ${OBJ}


${OBJ_DIR}%.o: ${SRC_DIR}%.c
	${CC} ${IFLAG} ${CFLAG} ${DFLAG} -c $< -o $@

-include ${OBJ_DIR}/*.dep


#	==============================	UTILS	==============================	#
${OBJ_DIR}:
	@mkdir ${OBJ_DIR}

# end
