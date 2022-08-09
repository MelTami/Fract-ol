NAME			= fractol

CFLAGS			= -Wall -Werror -Wextra

RM				= rm -rf
			
PATH_INCLUDES	= ./includes/
PATH_OBJS		= ./objects/
PATH_SRCS		= ./sources/
PATH_LIBFT		= ./Libft

SRCS			= $(addprefix $(PATH_SRCS), main.c)
LFLAGS			= -L $(PATH_LIBFT) -lft
OBJS 			= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))
INCLUDES		= -I $(PATH_INCLUDES)

all:	$(NAME)

$(NAME): $(OBJS)
	make -C $(PATH_LIBFT)
	cc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LFLAGS)


$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	mkdir -p $(PATH_OBJS)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		$(RM) $(PATH_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re