# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvavasso <mvavasso@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 23:00:10 by mvavasso          #+#    #+#              #
#    Updated: 2022/10/15 15:53:15 by mvavasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fractol

CFLAGS			= -Wall -Werror -Wextra

RM				= rm -rf
			
PATH_INCLUDES	= ./includes/
PATH_OBJS		= ./objects/
PATH_SRCS		= ./sources/
PATH_LIBFT		= ./Libft

MINILIBX_PATH	=	./minilibx-linux/
MINILIBX		=	$(MINILIBX_PATH)libmlx.a

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
MLXFLAGS		= -L$(MINILIBX_PATH) -lXext -lX11 -lmlx_Linux -lmlx

all:	$(NAME)

$(NAME): $(OBJS)
	make -C $(PATH_LIBFT)
	make -C $(MINILIBX_PATH)
	clang $(CFLAGS) $(INCLUDES) $(OBJS) $(LFLAGS) $(MINILIBX) $(MLXFLAGS) -o $(NAME)


$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	mkdir -p $(PATH_OBJS)
	clang $(CFLAGS) $(INCLUDES) -I mlx.h -O3 -c $< -o $@

clean:
		$(RM) $(PATH_OBJS)
		make clean -C $(PATH_LIBFT)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(PATH_LIBFT)

re:		fclean all

.PHONY: all clean fclean re