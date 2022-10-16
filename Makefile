# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 23:00:10 by mvavasso          #+#    #+#              #
#    Updated: 2022/10/16 17:57:48 by mvavasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

CFLAGS			= -Wall -Werror -Wextra

RM				= rm -rf
			
PATH_INCLUDES	= ./includes/
PATH_OBJS		= ./objects/
PATH_SRCS		= ./sources/
PATH_LIBFT		= ./libft

SRCS			= $(addprefix $(PATH_SRCS), \
					main.c \
					ft_name.c \
					Mandelbrot.c \
					Julia.c \
					mousehooks.c \
					keyhooks.c \
					set_color.c \
					ft_atof.c \
					render.c \
					colors_sets.c)
LFLAGS			= -L $(PATH_LIBFT) -lft
OBJS 			= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))
INCLUDES		= -I $(PATH_INCLUDES)
MLXFLAGS		= -lmlx -lXext -lX11 -lm -lz

all:	$(NAME)

$(NAME): $(OBJS)
	@ make -C $(PATH_LIBFT)
	@ clang $(CFLAGS) $(OBJS) $(LFLAGS) $(MLXFLAGS) -o $(NAME)
	@ echo -e '\033[0;32m[SUCCESS]\033[0m Compilation done!'

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@ mkdir -p $(PATH_OBJS)
	@ clang $(CFLAGS) $(INCLUDES) -I mlx.h -O3 -c $< -o $@
	
clean:
	@ $(RM) $(PATH_OBJS)
	@ make clean -C $(PATH_LIBFT)
	@ echo -e '\033[0;33mObjects removed\033[0m'

fclean:	clean
	@ $(RM) $(NAME)
	@ make fclean -C $(PATH_LIBFT)
	@ echo -e '\033[0;33mEverything is clean\033[0m'

re:		fclean all

.PHONY: all clean fclean re