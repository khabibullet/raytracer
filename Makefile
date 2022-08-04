# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 21:25:23 by anemesis          #+#    #+#              #
#    Updated: 2022/08/04 14:03:04 by anemesis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT

HEADERS		=	headers/*

SRCDIR		=	sources

OBJDIR		=	objects

SRC			=	$(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c)

OBJ			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror

LIBS		=	./libraries/libft/libft.a ./libraries/libmlx/libmlx.a

INC			=	-I ./headers -I ./libraries/libft -I ./libraries/libmlx

LIB_FT		=	-L ./libraries/libft/ -lft

LIB_MLX		=	-L ./libraries/libmlx/ -lmlx -framework OpenGL -framework AppKit

# **************************************************************************** #

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(LIB_FT) $(LIB_MLX) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(LIBS) $(HEADERS)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(@:/$(notdir $@)=)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBS) :
	make -C libraries/libft
	make -C libraries/libmlx

clean :
	rm -rf $(OBJDIR)
	make clean -C libraries/libft
	make clean -C libraries/libmlx

fclean : clean
	rm -f $(NAME)
	make fclean -C libraries/libft
	make fclean -C libraries/libmlx

re : fclean all

.PHONY : all clean fclean re