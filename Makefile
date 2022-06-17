# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 21:25:23 by anemesis          #+#    #+#              #
#    Updated: 2022/06/17 22:09:22 by anemesis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minirt

HEADER		=	headers/minirt.h

SRCDIR		=	sources

OBJDIR		=	objects

LIBDIR		=	libraries

SRC			=	$(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c)

OBJ			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

LIBS		=	./$(LIBDIR)/libft/libft.a ./$(LIBDIR)/libmlx/libmlx.dylib

INC			=	-I ./headers -I ./libraries/libft -I ./libraries/libmlx

LIB_FT		=	-L ./$(LIBDIR)/libft/ -lft

LIB_MLX		=	-lmlx -framework OpenGL -framework AppKit

# **************************************************************************** #

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER) $(LIBS)
	make -C $(LIBDIR)/libft
	make -C $(LIBDIR)/libmlx
	$(CC) $(FLAGS) $(INC) $(LIB_FT) $(LIB_MLX) $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(@:/$(notdir $@)=)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)
	make clean -C $(LIBDIR)/libft
	make clean -C $(LIBDIR)/libmlx

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBDIR)/libft
	make fclean -C $(LIBDIR)/libmlx

re : fclean all

.PHONY : all clean fclean re $(NAME) $(LIBS)
