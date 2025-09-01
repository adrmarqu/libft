# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 16:54:34 by adrmarqu          #+#    #+#              #
#    Updated: 2025/09/01 14:24:38 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

NAME = libft.a

SRC = ft_alphanum.c ft_ascii.c ft_ato.c ft_strl.c ft_compare.c ft_search.c \
	  ft_mem.c ft_fill.c ft_convert.c ft_alloc.c

CTP_D = ./sources/ctype/
EXT_D = ./sources/extra/
STR_D = ./sources/string/
MEM_D = ./sources/memory/

OBJ_F = ${SRC:.c=.o}
OBJ_D = ./objects/
OBJ = $(addprefix ${OBJ_D}, ${OBJ_F})

DEP_F = ${SRC:.c=.d}
DEP_D = ./dependencies/
DEP = $(addprefix ${DEP_D}, ${DEP_F})

all: ${NAME}

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

vpath %.c $(CTP_D) $(EXT_D) $(STR_D) $(MEM_D)

$(OBJ_D)%.o: %.c Makefile | $(OBJ_D) $(DEP_D)
	$(CC) $(CFLAGS) -MMD -MF $(DEP_D)$*.d -c $< -o $@

$(OBJ_D):
	mkdir -p $@

$(DEP_D):
	mkdir -p $@

clean:
	$(RM) $(OBJ) $(DEP)
	@echo "---> Deleted objects and dependencies"

fclean: clean
	$(RM) $(NAME)
	@echo "---> Deleted libft.a"

re: fclean all

.PHONY: all clean fclean re
