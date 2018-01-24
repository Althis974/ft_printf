# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rlossy <marvin@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 09:43:34 by rlossy       #+#   ##    ##    #+#        #
#    Updated: 2018/01/23 12:32:19 by rlossy      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=	libftprintf.a
LIB_DIR		=	./libft
HEADER		=	ft_printf.h
FILENAMES	=	ft_printf.c ft_format.c ft_prefix.c ft_check_char.c
FILENAMES	+=	ft_check_int.c ft_flag.c ft_spec.c ft_u2ls_nb.c ft_utils_nb.c
FILENAMES	+=	ft_exceptions.c ft_cast.c ft_utils_char.c ft_u2ls_char.c

SOURCES		=	$(addprefix ./, $(FILENAMES))
OBJECTS		=	$(addprefix build/, $(FILENAMES:.c=.o)) 

L_FT		=	$(LIB_DIR)
LIB_LNK		=	$(L_FT)/libft.a
LIB_INC		=	-I $(L_FT)/libft.h


.PHONY: all clean fclean re


all: $(NAME)

clean:
	@echo "\033[31m"
	rm -rf build/
	@$(MAKE) -C $(L_FT) clean

fclean: clean
	@echo "\033[31m"
	rm -f $(NAME)
	@$(MAKE) -C $(L_FT) fclean

re: 
	@$(MAKE) fclean 
	@$(MAKE) all

build: 
	@echo "\033[35m"
	mkdir build/

$(NAME): $(OBJECTS)
	@$(MAKE) -C $(L_FT)
	@echo "\033[32m"
		libtool -v -static -o $@ $^ $(LIB_LNK) 

build/%.o: ./%.c | build
	gcc -Wall -Wextra -Werror $(LIB_INC) -I $(HEADER) -c $< -o $@
