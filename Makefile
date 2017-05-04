# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#              #
#    Updated: 2017/05/04 12:43:55 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS =  -fsanitize=address -g -o push_swap_debug
LEAKCHECKFLAGS = -g -o push_swap_leakcheck
SRCF = push_swap.c \
	   read_input.c \

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./src/
LIBDIR = ./libft/
FTPFDIR = ./ft_printf/
INCDIR = ./include/

.PHONY: $(NAME), all, clean, fclean, re, $(LIBFT)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF)
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "push_swap: SUCCESS!"

$(LIBFT):
	@make -C $(LIBDIR) all

$(FT_PRINTF):
	@make -C $(FTPFDIR) all

clean:
	@echo "Cleaning push_swap"
	@rm -rf $(OBJDIR)
	@rm -rf push_swap_debug
	@rm -rf push_swap_debug.dSYM
	@rm -rf push_swap_leakcheck
	@rm -rf push_swap_leakcheck.dSYM
	@make -C $(LIBDIR) clean
	@make -C $(FTPFDIR) clean

fclean: clean
	@echo "FCleaning push_swap"
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean
	@make -C $(FTPFDIR) fclean

re: fclean all

debug: $(LIBFT)
	@echo "Compiling push_swap with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck: $(LIBFT)
	@echo "Compiling push_swap for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) $(LEAKCHECKFLAGS)