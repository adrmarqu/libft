# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 16:54:34 by adrmarqu          #+#    #+#              #
#    Updated: 2025/09/04 20:32:13 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

NAME = libft.a

SRC = ft_alphanum.c ft_ascii.c ft_ato.c ft_strl.c ft_compare.c ft_search.c	\
	  ft_mem.c ft_fill.c ft_convert.c ft_alloc.c ft_map.c ft_strings.c		\
	  ft_join.c ft_output.c ft_length.c ft_itoa.c ft_split.c fd_printf.c	\
	  get_next_line.c handle_input.c flags.c print.c

CTP_D = ./sources/ctype/
EXT_D = ./sources/extra/
STR_D = ./sources/string/
MEM_D = ./sources/memory/
GNL_D = ./sources/get_next_line/
FDP_D = ./sources/fd_printf/

OBJ_F = ${SRC:.c=.o}
OBJ_D = ./objects/
OBJ = $(addprefix ${OBJ_D}, ${OBJ_F})

DEP_F = ${SRC:.c=.d}
DEP_D = ./dependencies/
DEP = $(addprefix ${DEP_D}, ${DEP_F})

all: ${NAME}

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)

vpath %.c $(CTP_D) $(EXT_D) $(STR_D) $(MEM_D) $(GNL_D) $(FDP_D)

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
