##
# leadwasp
#
# @file makefile
# @version 0.2


#	==============================	NAME	==============================	#
NAME		=	leadwasp
NAME_BONUS	=	leadwasp_bonus
DIR_LIBUNIT	=	external/libunit/libunit


#	==============================	CMP	==============================	#
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g3
DFLAG		=	-MMD -MP


#	==============================	INCLUDE	==============================	#
DIR_INC		=	inc/ ${DIR_LIBUNIT}/inc
IFLAGS		=	$(DIR_INC:%=-I%)


#	==============================	SRC	==============================	#
SRC_DIR			=	src/
SRC_SUBDIR_LST	=	strlen strcpy strcmp strdup write read atoi_base list_size list_sort list_remove_if list_push_front
SRC_SUBDIR		=	${addprefix ${SRC_DIR}, ${SRC_SUBDIR_LST}}

SRC_FILE		=	src.mk
-include ${SRC_FILE}

SRC_LST			=	main.c \
					${STRLEN_SRC} ${STRCPY_SRC} ${STRCMP_SRC} ${STRDUP_SRC} ${WRITE_SRC} ${READ_SRC}

SRC_BONUS_LST	=	main_bonus.c \
					${ATOI_BASE_SRC} #${LIST_SIZE_SRC} ${LIST_SORT_SRC} ${LIST_REMOVE_IF_SRC} ${LIST_PUSH_FRONT_SRC}

SRC				= ${addprefix ${SRC_DIR}, ${SRC_LST}}
SRC_BONUS		= ${addprefix ${SRC_DIR}, ${SRC_BONUS_LST}}


#	==============================	OBJ	==============================	#
OBJ_DIR		=	.obj/
OBJ_SUBDIR	=	${addprefix ${OBJ_DIR}, ${SRC_SUBDIR}}

OBJ_TMP		=	${addprefix ${OBJ_DIR}, ${SRC}}
OBJ_TMP_B	=	${addprefix ${OBJ_DIR}, ${SRC_BONUS}}
OBJ			=	${OBJ_TMP:.c=.o}
OBJ_BONUS	=	${OBJ_TMP_B:.c=.o}

DEPS		=	${OBJ:.o=.d}


#	==============================	LIB	==============================	#
LIBUNIT		=	${DIR_LIBUNIT}/libunit.a
LIBASM		=	../libasm.a



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY: mandatory bonus all m b a clean fclean

#	==============================	BASE	==============================	#
mandatory:	${NAME}
m:	mandatory

bonus:	${NAME_BONUS}
b:	bonus

all: mandatory bonus
a:	all

strlen:	mandatory
strcpy:	mandatory
strcmp:	mandatory
strdup:	mandatory
read:	mandatory
write:	mandatory

atoi_base:			bonus
list_size:			bonus
list_push_front:	bonus
list_sort:			bonus
list_remove_if:		bonus

clean:
	@rm -rf ${OBJ_DIR}

fclean: clean
	@rm -f ${NAME} ${NAME_BONUS}

re: fclean all


#	==============================	COMPILATION	==============================	#
${NAME}: ${LIBUNIT} ${OBJ_SUBDIR} ${OBJ}
	${CC} ${IFLAGS} ${CFLAGS} ${OBJ} ${LIBUNIT} ${LIBASM} -o $@

${NAME_BONUS}: ${LIBUNIT} ${OBJ_SUBDIR} ${OBJ_BONUS}
	${CC} ${IFLAGS} ${CFLAGS} ${OBJ_BONUS} ${LIBUNIT} ${LIBASM} -o $@

${OBJ_DIR}%.o: %.c 
	${CC} ${IFLAGS} ${CFLAGS} ${DFLAG} -c $< -o $@

${LIBUNIT}:
	make -C ${DIR_LIBUNIT}

-include ${DEPS}


#	==============================	UTILS	==============================	#
${OBJ_SUBDIR}:
	@mkdir -p ${OBJ_SUBDIR}


# end
