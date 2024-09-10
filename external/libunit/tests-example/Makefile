##
# tests
#
# @file makefile
# @version 0.2


#	==============================	NAME	==============================	#
NAME		=	exampler.out
DIR_LIBUNIT	=../libunit

#	==============================	CMP	==============================	#
CC			=	gcc 
CFLAG		=	-Wall -Wextra -Werror -g3
DFLAG		=	-MMD -MP


#	==============================	INCLUDE	==============================	#
DIR_INC		=	inc/
IFLAG		=	-I ${DIR_INC} -I ${DIR_LIBUNIT}/inc


#	==============================	SRC	==============================	#
# STRLEN
STRLEN_SRC_DIR	=	strlen/
STRLEN_SRC_LST	=	00_launcher_strlen.c \
					01_ok_short.c \
					02_ok_long.c \
					03_ko_bad_result.c \
					04_ko_segv.c \
					05_ko_buse.c \
					06_ko_timeout.c 

# STRLEN
WRITE_SRC_DIR	=	write/
WRITE_SRC_LST	=	00_launcher_write.c \
					01_ok_short_string.c \
					02_ok_short_string_ret.c \
					03_ok_empty.c \
					04_ko_bad_fd.c 

STRLEN_SRC		=	${addprefix ${STRLEN_SRC_DIR}, ${STRLEN_SRC_LST}}
WRITE_SRC		=	${addprefix ${WRITE_SRC_DIR}, ${WRITE_SRC_LST}}
SRC_MAIN		=	main.c

#	==============================	OBJ	==============================	#
OBJ_DIR		=	.obj/
OBJ_LST		=	${SRC_MAIN:.c=.o} \
				${STRLEN_SRC_LST:.c=.o} \
				${WRITE_SRC_LST:.c=.o}

OBJ			=	${addprefix ${OBJ_DIR}, ${OBJ_LST}}

#	==============================	OBJ	==============================	#
LIBUNIT		=	${DIR_LIBUNIT}/libunit.a

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

test:	${NAME}
	@./${NAME}


#	==============================	COMPILATION	==============================	#
${NAME}: ${LIBUNIT} ${OBJ_DIR} ${OBJ}
	${CC} ${IFLAG} ${CFLAG} ${OBJ} ${LIBUNIT} -o $@


${OBJ_DIR}%.o: ${STRLEN_SRC_DIR}%.c
	${CC} ${IFLAG} ${CFLAG} ${DFLAG} -c $< -o $@

${OBJ_DIR}%.o: ${WRITE_SRC_DIR}%.c
	${CC} ${IFLAG} ${CFLAG} ${DFLAG} -c $< -o $@

${OBJ_DIR}%.o: %.c
	${CC} ${IFLAG} ${CFLAG} ${DFLAG} -c $< -o $@

${LIBUNIT}:
	make -C ${DIR_LIBUNIT}

-include ${OBJ_DIR}/*.dep


#	==============================	UTILS	==============================	#
${OBJ_DIR}:
	@mkdir ${OBJ_DIR}


# end
