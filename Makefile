NAME		=	so_long
SRS_DIR		=	src
OBJ_DIR		=	obj
MLX_PATH	=	mlx
INCLUDE_DIR	=	include
INCS		=	-I$(INCLUDE_DIR) -I$(MLX_PATH)
LINKERS		=	-L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit



SORCS		=	$(wildcard $(SRS_DIR)/*.c)
OBJS		=	$(patsubst $(SRS_DIR)/.c,$(OBJ_DIR)/.o,$(SORCS))
HEADERS		=	$(wildcard $(INCLUDE_DIR)/*.h)

# Executable Name
.DEFAULT_GOAL = all

# Command Flags
CC			=	cc
MK			=	mkdir -p
FLAGS		=	-Wall -Wextra -Werror

mlx:	$(SRS_DIR)
	$(MAKE) -C $(MLX_PATH)

$(OBJ_DIR):		$(SRS_DIR)
	$(MK) $@

$(OBJ_DIR)/%.o: $(SRS_DIR)/%.c $(HEADERS)
	$(CC) $(FLAGS) $(INCS) $< -o $@

all:	mlx $(NAME)

$(NAME):	$(OBJ_DIR)	$(OBJS)
		$(CC) $(FLAGS) $(INCS)  -o $@ $(OBJS) $(LINKERS)
.PHONY: all clean fclean re mlx
