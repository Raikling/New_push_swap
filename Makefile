NAME = push_swap
SRCS = push_swap.c add_libft.c args_part.c errors_and_free.c stack_init.c swap.c rotate.c
OBJS = $(SRCS:.c=.o)
LIBFT = Libft/libft.a
FT_PRINTF = ft_Printf/libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -rf

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FT_PRINTF)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(dir $(LIBFT))
$(FT_PRINTF):
	make -C $(dir $(FT_PRINTF))

clean:
	$(RM) $(OBJS)
	make -C Libft clean
	make -C ft_Printf clean

fclean: clean
	$(RM) $(NAME)
	make -C Libft fclean
	make -C ft_Printf fclean
	
re : fclean all

.PHONY: all clean fclean re
