##
# libasm
#
# @file
# @version 0.2


#	==============================	NAME	==============================	#
LIB_PATH		=	../libasm
LIB_NAME		=	libasm.a
LIBASM			=	${LIB_PATH}/${LIB_NAME}
NAME			=	asm64test.out

#	==============================	CMP	==============================	#
CC			=	gcc 
CFLAG		=	-Wall -Wextra -Werror -g3 #-fsanitize=address,leak,undefined 


#	==============================	INCLUDE	==============================	#
DIR_INC		=	include/
IFLAG		=	-I ${DIR_INC}


#	==============================	SRC	==============================	#
DIR_TEST		=	test/

LST_SRC			=	main.c utils.c strlen.c strcpy.c strcmp.c strdup.c write.c read.c atoi_base.c list_push_front.c list_size.c list_sort.c list_remove_if.c 
SRC				=	${addprefix ${DIR}, ${LST_SRC}}

LST_SRC_BONUS	=	atoi_base.c list_push_front.c list_size.c list_sort.c list_remove_if.c 
SRC_BONUS		=	${addprefix ${DIR}, ${LST_SRC_BONUS}}


#	==============================	OBJ	==============================	#
DIR_OBJ			= .obj/

LST_OBJ			=	${LST_SRC:.c=.o}
LST_OBJ_BONUS	=	${LST_SRC_BONUS:.c=.o}

OBJ				=	${addprefix ${DIR_OBJ}, ${LST_OBJ}}
OBJ_BONUS		=	${addprefix ${DIR_OBJ}, ${LST_OBJ_BONUS}}



#	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	RULES	/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\/*\	#
.PHONY: all clean fclean
#	==============================	BASE	==============================	#
all: ${NAME}


clean:
	@rm -rf ${DIR_OBJ}
	@echo "Clean"

fclean: clean
	@rm -f ${NAME}
	@echo "FClean"

re: fclean all


#	==============================	COMPILATION	==============================	#
${NAME}:	${DIR_OBJ} ${OBJ}
	${CC} ${IFLAG} ${CFLAG} ${OBJ} ${LIBASM} -o ${NAME} 

# ${LIBASM}:


${DIR_OBJ}%.o:	${DIR_TEST}%.c
	${CC} ${IFLAG} ${CFLAG} -c $< -o $@


-include ${DIR_OBJ}/*.dep


#	==============================	UTILS	==============================	#
${DIR_OBJ}:
	@mkdir ${DIR_OBJ}




# end
