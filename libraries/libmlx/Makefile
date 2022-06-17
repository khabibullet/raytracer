
MODULE_SRC		=	mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_SRC_DIR	=	s_sources
MODULE_SOURCES	=	$(addprefix $(MODULE_SRC_DIR)/,$(MODULE_SRC))

MODULE_OBJ		=	$(MODULE_SRC:%.swift=%.swiftmodule)
MODULE_DIR		=	modules
MODULES			=	$(addprefix $(MODULE_DIR)/,$(MODULE_OBJ))

OBJ_DIR			=	objects

SRC				=	$(addprefix $(MODULE_SRC_DIR)/,interface.swift $(MODULE_SRC))
OBJ				=	$(SRC:$(MODULE_SRC_DIR)/%.swift=$(OBJ_DIR)/%.o)

C_SRC_DIR		=	c_sources
C_SRC			=	$(wildcard $(C_SRC_DIR)/*.c)
C_OBJ			=	$(C_SRC:$(C_SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME			=	libmlx.dylib

INC				=	-I $(MODULE_DIR)/

all: $(NAME)

$(NAME): $(MODULES) $(OBJ) $(C_OBJ)
	swiftc $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz

$(OBJ_DIR)/%.o: $(C_SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc -c $< -o $@

$(OBJ_DIR)/%.o: $(MODULE_SRC_DIR)/%.swift
	@mkdir -p $(OBJ_DIR)
	swiftc $(INC) -parse-as-library -c $< -o $@

$(MODULE_DIR)/%.swiftmodule: $(MODULE_SRC_DIR)/%.swift
	@mkdir -p $(MODULE_DIR)
	swiftc $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(notdir $(patsubst %.swift,%,$<)) -module-link-name $(notdir $(patsubst %.swift,%,$<))

clean:
	rm -rf objects modules

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY : all clean fclean re $(NAME)