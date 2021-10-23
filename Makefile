NAME			=	fractol

SRCS_DIR		=	./srcs/

OBJS_DIR		=	./objs/

HEADERS_DIR		=	./headers/

LIBFT_DIR		=	./libft/

SRCS			=	$(SRCS_DIR) fractol.c \

HEADERS			=	$(wildcard $(HEADERS_DIR)*.h)

OBJS			=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

LDFLAGS			=	-L$(LIBMLX_DIR) -lmlx -L$(LIBFT_DIR) -framework OpenGL -framework Appkit -O3

RM				=	rm -f

LIBFT			=	$(addprefix $(LIBFT_DIR), libft.a)

LIBMLX			=	$(addprefix $(LIBMLX_DIR), libmlx.a)

LIBFT_DIR		=	./libft/

LIBMLX_DIR		=	./minilibx_opengl_20191021/

all:	$(LIBFT) $(LIBMLX) $(NAME)
$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(HEADERS) $(LIBFT) $(LIBMLX_DIR)/libmlx.a | $(OBJS_DIR)
	$(CC) $(CFLAGS) -O3 -I$(HEADERS_DIR) -Imlx -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX_DIR)/libmlx.a
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
# gcc -o $(NAME) $(OBJS) $(LIBMLX_DIR)/libmlx.a

clean:
		$(RM) -r $(OBJS_DIR)
		make clean -C $(LIBFT_DIR) fclean

fclean: clean
		$(RM) $(NAME)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

re:	fclean $(OBJS_DIR) all

.PHONY:	all clean fclean re