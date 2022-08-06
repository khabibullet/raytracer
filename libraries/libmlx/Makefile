# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 11:52:34 by anemesis          #+#    #+#              #
#    Updated: 2022/08/06 23:24:52 by anemesis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libmlx.a

SRC		=	mlx_shaders.c		mlx_new_window.m	mlx_init_loop.m \
			mlx_new_image.m		mlx_xpm.c			mlx_int_str_to_wordtab.c \
			mlx_png.c			mlx_mouse.m

SRCDIR	=	sources

OBJDIR	=	objects

OBJ		=	$(addprefix $(OBJDIR)/,$(patsubst %.m,%.o,$(patsubst %.c,%.o,$(SRC))))

CC		=	cc

CFLAGS	=	-O2 -DSTRINGPUTX11 -w

all : $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.m
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re