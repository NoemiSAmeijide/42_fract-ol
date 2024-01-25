# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosilves <nosilves@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 21:41:25 by nosilves          #+#    #+#              #
#    Updated: 2023/12/27 20:39:23 by nosilves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------COLORS-------------------------------#
BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#-------------------------------VARIABLES-----------------------------#

NAME = fractol
CC = cc
RM = rm -rf
GFLAGS	= -framework OpenGL -framework Appkit
MLX_DIR	= ./$(LIBS)mlx_Darwin/
CFLAGS	= -Wall -Wextra -Werror -W -g -Ofast
SRC = main.c fractals.c validations.c hooks.c colors.c fractol_utils.c
OBJ = ${SRC:.c=.o}


#--------------------------IMPLICIT METHODS--------------------------#

%.o:%.c fractol.h macro.h mlx/libmlx.a Makefile
	@printf "${YELLOW}\rCompiling (╮°-°)╮┳━┳ ${GREEN} : $<\n" 
	$(CC) $(CFLAGS) -c $< -o $@

#-----------------------------FUNCTIONS-------------------------------#

all: 	make_libs $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(GFLAGS) -Lmlx -lmlx $(GFLAGS) -o $(NAME)
	printf "\n$(GREEN)[ $(NAME) compiled! ]$(DEF_COLOR)\n"

make_libs:
		@MAKE -C mlx

bonus: all

clean:
	@echo "${RED}Cleaning... (ノಠ益ಠ)ノ彡┻━┻${GRAY}"
	@MAKE -C mlx clean
	$(RM) $(OBJ)


fclean: clean
	@echo "Cleaning all!!!🧼"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re  
