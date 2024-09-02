##
# libasm
#
# @file
# @version 0.2

#	==============================	NAME	==============================	#
LIB_PATH		=	../libasm
LIB_NAME		=	libasm.a
LIBASM			=	${LIB_PATH}/${LIB_NAME}


#	==============================	CMP	==============================	#
CC			=	gcc 
CFLAG		=	-Wall -Wextra -Werror -g3 #-fsanitize=address,leak,undefined 
DFLAGS		=	-MMD -MP

#	==============================	INCLUDE	==============================	#
DIR_INC		=	include/
IFLAG		=	-I ${DIR_INC}


#	==============================	SRC	==============================	#
DIR_SRC			=	src/

LST_SRC			=	strlen.c strcpy.c strcmp.c strdup.c write.c read.c 
LST_UTILS		=	utils.c
LST_SRC_BONUS	=	atoi_base.c list_push_front.c list_size.c list_sort.c list_remove_if.c 

SRC				=	${addprefix ${DIR}, ${LST_SRC}}
UTILS			=	${addprefix ${DIR}, ${LST_UTILS}}
SRC_BONUS		=	${addprefix ${DIR}, ${LST_SRC_BONUS}}


#	==============================	OBJ	==============================	#
DIR_OBJ			=	.obj/

LST_OBJ			=	${LST_SRC:.c=.o}
LST_OBJ_UTILS	=	${LST_UTILS:.c=.o}
LST_OBJ_BONUS	=	${LST_SRC_BONUS:.c=.o}

OBJ				=	${addprefix ${DIR_OBJ}, ${LST_OBJ}}
OBJ_UTILS		=	${addprefix ${DIR_OBJ}, ${LST_OBJ_UTILS}}
OBJ_BONUS		=	${addprefix ${DIR_OBJ}, ${LST_OBJ_BONUS}}


#	==============================	BIN	==============================	#
DIR_BIN			=	bin/

LST_BIN			=	${LST_OBJ:.o=.out}
LST_BIN_BONUS	=	${LST_OBJ_BONUS:.o=.out}

BIN				=	${addprefix ${DIR_BIN}, ${LST_BIN}}
BIN_BONUS		=	${addprefix ${DIR_BIN}, ${LST_BIN_BONUS}}



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY: all clean fclean
#	==============================	BASE	==============================	#
a:	all
all:	mandatory bonus

clean:
	@rm -rf ${DIR_OBJ}

fclean:	clean
	@rm -rf ${DIR_BIN}

re:		fclean all


#	==============================	COMPILATION	==============================	#
precomp:	${DIR_BIN} ${DIR_OBJ} ${OBJ_UTILS} ${OBJ} ${OBJ_BONUS}


m:	mandatory
mandatory:	precomp ${BIN}

b:	bonus
bonus:	precomp ${BIN_BONUS}

${DIR_OBJ}%.o:	${DIR_SRC}%.c
	${CC} ${IFLAG} ${CFLAG} ${DFLAGS} -c $< -o $@

${DIR_BIN}%.out:	${DIR_OBJ}%.o ${LIBASM}
	${CC} ${IFLAG} ${CFLAG} ${OBJ_UTILS} $< ${LIBASM} -o $@

-include ${DIR_OBJ}/*.dep


#	==============================	UTILS	==============================	#
${DIR_OBJ}:
	@mkdir ${DIR_OBJ}

${DIR_BIN}:
	@mkdir ${DIR_BIN}

${LIBASM}:

# end
