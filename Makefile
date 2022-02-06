SRC = main.c \
ft_atoi.c \
stack_utils.c \
sort_three.c \
sort_five.c \
sort_regular.c \
utils.c \
lis.c \

CC = gcc

HEADER = push_swap.h

OBJ = $(SRC:%.c=./.build/%.o)

NAME = push_swap

RM = rm -rf

LIBC = ar -rc

CFLAGS = -Wall -Wextra -Werror

LIBFT = @printf "\n\t\t${B_CYAN}GENERATE libft library ...\n\n${NONE}" && cd libft && make bonus && make all

SWAPPER = @printf "\n\t\t${B_CYAN}GENERATE SWAPPER library ...\n\n${NONE}" && cd swapper && make all

# COLORS
NONE			= \033[0m
CL_LINE			= \033[2K
B_RED			= \033[1;31m
B_GREEN			= \033[1;32m
B_MAGENTA 		= \033[1;35m
B_CYAN 			= \033[1;36m

./.build/%.o : %.c
	@$(CC) ${CFLAGS} -I. -o $@ -c $?
	@printf "${B_MAGENTA}Compilling $? ...\n${NONE}"

all :	
	@mkdir -p .build
	@make ${NAME}

${NAME} : $(OBJ)
	${SWAPPER}
	@${CC} -o ${NAME} ${OBJ} swapper/swapper.a
	@printf "${B_GREEN}==>{${NAME}} LINKED SUCCESFULLY<==${NONE}\n"

clean :
	@${RM} .build
	@printf "${B_RED}XX{${NAME}} CLEANED SUCCESFULLY XX${NONE}\n"

fclean :	clean
	@${RM} ${NAME}
	@cd swapper && make fclean
	@printf "${B_RED}XX{${NAME}} FCLEAN SUCCESFULL XX${NONE}\n"

re :	fclean all