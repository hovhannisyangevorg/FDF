NAME 		= 	fdf
SRC_DIR 	= 	src
OBJ_DIR		= 	obj
INC_DIR		=	include
MLX_DIR		=	mlx

FT_LIB			= libft
LIBS			= $(FT_LIB)/libft.a

CC			=	cc
INCS		=	-I$(INC_DIR) -I$(MLX_DIR) -I$(FT_LIB)/include
CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address
RM			=	rm -rf
MK			=	mkdir -p

SRCS		= 	$(wildcard $(SRC_DIR)/*.c)
OBJS		=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
HEADERS		=	$(wildcard $(INC_DIR)/*.h)
LINKERS		=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L$(FT_LIB) -lft

.DEFAULT_GOAL	=	all

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all: $(NAME) $(LIBS)

$(NAME):	$(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCS) -o $@ $(LINKERS)

$(LIBS):
	$(MAKE) -C $(FT_LIB)

$(OBJ_DIR):	$(SRC_DIR)
	$(MK) $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

#  DYLD_LIBRARY_PATH=`pwd`/mlx ./fdf
#  -g3 -fsanitize=address
.PHONY: all clean fclean re 
