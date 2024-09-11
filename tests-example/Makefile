##
# tests
#
# @file makefile
# @version 0.2


#	==============================	NAME	==============================	#
NAME		=	exampler.out
DIR_LIBUNIT	=	../libunit


#	==============================	CMP	==============================	#
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
DFLAG		=	-MMD -MP


#	==============================	INCLUDE	==============================	#
DIR_INC		=	inc/ ${DIR_LIBUNIT}/inc
IFLAGS		=	$(DIR_INC:%=-I%)


#	==============================	SRC	==============================	#
SRC_DIRS		=	strlen write

# STRLEN
STRLEN_SRC_DIR	=	strlen/
STRLEN_SRC_LST	=	00.c 01.c 02.c 03.c 04.c 05.c 06.c
STRLEN_SRC		=	${addprefix ${STRLEN_SRC_DIR}, ${STRLEN_SRC_LST}}

# WRITE
WRITE_SRC_DIR	=	write/
WRITE_SRC_LST	=	00.c 01.c 02.c 03.c 04.c
WRITE_SRC		=	${addprefix ${WRITE_SRC_DIR}, ${WRITE_SRC_LST}}

SRC_ALL			=	main.c \
					${STRLEN_SRC} \
					${WRITE_SRC}


#	==============================	OBJ	==============================	#
OBJ_DIR		=	.obj/
OBJ_SUBDIR	=	${addprefix ${OBJ_DIR}, ${SRC_DIRS}}
OBJ_TMP		=	${addprefix ${OBJ_DIR}, ${SRC_ALL}}

OBJ			=	${OBJ_TMP:.c=.o}
DEPS		=	${OBJ:.o=.d}


#	==============================	LIB	==============================	#
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
	${CC} ${IFLAGS} ${CFLAGS} ${OBJ} ${LIBUNIT} -o $@

${OBJ_DIR}%.o: %.c
	${CC} ${IFLAGS} ${CFLAGS} ${DFLAG} -c $< -o $@

${LIBUNIT}:
	make -C ${DIR_LIBUNIT}

-include ${DEPS}


#	==============================	UTILS	==============================	#
${OBJ_DIR}:
	@mkdir ${OBJ_DIR} ${OBJ_SUBDIR}


# end
