#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svovchyn <svovchyn@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 13:17:38 by svovchyn          #+#    #+#              #
#    Updated: 2018/11/22 13:31:19 by svovchyn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

FLAGS = -Wall -Wextra -Werror $(INC)
LIB = $(LIBDIR)/libft.a
DEL = rm
LIBFLAGS = -L $(LIBDIR) -lft

LIBDIR = ./libft
SRCDIR = ./src
OBJDIR = $(SRCDIR)/obj

SRC = main.c	solver.c 	tetri_management.c 	tetri_utils.c 	utils.c
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INC = -I $(LIBDIR)/inc -I $(SRCDIR)


all : $(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
			@gcc -c $(FLAGS) $< -o $@ 

$(NAME): $(OBJ)
		@$(MAKE) -C $(LIBDIR)
		@gcc $(FLAGS) $(LIB) $(OBJ) -o $(NAME)
		@echo "LIBRARY AND FILLIT COMPILED"


$(OBJ): | $(OBJDIR)

$(OBJDIR):
		@mkdir $(OBJDIR)

libcomp:
		@$(MAKE) -C $(LIBDIR)

clean:
		@$(MAKE) -C $(LIBDIR) fclean
		@$(DEL) -rf $(OBJDIR)
		@echo "LIBRARY AND OBJECTS DELETED"

fclean: clean
		@$(DEL) -f $(NAME)
		@echo "PROJECT IS CLEANED"	

re: fclean all