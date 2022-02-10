SRC = main.c \
../utils.c \
../parsing.c \
../stack_utils.c \
../ft_atoi.c \

CC = gcc

HEADER = checker.h

OBJ = $(SRC:%.c=./.build/%.o)

NAME = checker

RM = rm -rf

LIBC = ar -rc

CFLAGS = -Wall -Wextra -Werror

SWAPPER = @printf "\n\t\t${B_CYAN}GENERATE SWAPPER library ...\n\n${NONE}" && cd ../swapper && make all

GNL = @printf "\n\t\t${B_CYAN}GENERATE GNL library ...\n\n${NONE}" && cd ../gnl && make all

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
	${GNL}
	@${CC} -o ${NAME} ${OBJ} ../swapper/swapper.a ../gnl/gnl
	@printf "${B_GREEN}==>{${NAME}} LINKED SUCCESFULLY<==${NONE}\n"

clean :
	@${RM} .build
	@${RM} *.o
	@printf "${B_RED}XX{${NAME}} CLEANED SUCCESFULLY XX${NONE}\n"

fclean :	clean
	@${RM} ${NAME}
	@cd ../swapper && make fclean
	@cd ../gnl && make fclean
	@${RM} *.o
	@printf "${B_RED}XX{${NAME}} FCLEAN SUCCESFULL XX${NONE}\n"

re :	fclean all