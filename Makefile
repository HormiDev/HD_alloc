# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 18:18:19 by ide-dieg          #+#    #+#              #
#    Updated: 2026/03/13 04:07:07 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hd_alloc.a

CC = cc

AR = ar

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = -rcs

objdir = obj

src = hd_alloc.c \
      hd_alloc_error_func_c.c \
      hd_calloc.c \
      hd_u_add_last_hd_alloc_list.c \
      hd_u_get_hd_alloc_list_prev_node.c \
      hd_alloc_clear.c \
      hd_alloc_error_func_d.c \
      hd_free.c \
      hd_u_alloc_init.c \
      hd_u_get_last_hd_alloc_list.c \
      hd_alloc_error_func_a.c \
      hd_alloc_set_error_func.c \
      hd_malloc.c \
      hd_u_free_hd_alloc_list_node.c \
      hd_u_new_hd_alloc_list.c \
      hd_alloc_error_func_b.c \
      hd_alloc_set_error_ptr.c \
      hd_u_add_front_hd_alloc_list.c \
      hd_u_get_alloc.c \
	  hd_open.c

ROJO = \033[0;31m
NC = \033[0m
NARANJA = \033[0;33m
AZUL = \033[0;34m
VERDE = \033[0;32m

obj = ${src:.c=.o}

all: ide-dieg alloc_title $(NAME)
	@if [ -f $(NAME) ]; then \
		echo "$(VERDE)Compiled $(NAME) successfully!$(NC)"; \
	else \
		echo "$(ROJO)Failed to compile $(NAME)$(NC)"; \
	fi

$(NAME): $(obj:%=$(objdir)/%)
	@$(AR) $(ARFLAGS) $@ $^
	@echo

$(objdir):
	@mkdir -p $(objdir)

$(objdir)/%.o: %.c hd_alloc.h | $(objdir)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "█"

clean:
	@rm -fr $(objdir)
	@echo "$(ROJO)Removed object files$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(ROJO)Removed $(NAME)$(NC)"

re: fclean all

test: all
	mkdir .tmp
	@$(CC) $(CFLAGS) tests/test1.c $(NAME) -o test_hd_alloc; \
	if [ -f test_hd_alloc ]; then \
		echo "$(VERDE)Compiled test_hd_alloc successfully!$(NC)"; \
		valgrind ./test_hd_alloc; \
		rm -f test_hd_alloc; \
	else \
		echo "$(ROJO)Failed to compile test_hd_alloc$(NC)"; \
	fi
	@$(CC) $(CFLAGS) tests/test2.c $(NAME) -o test_hd_alloc; \
	if [ -f test_hd_alloc ]; then \
		echo "$(VERDE)Compiled test_hd_alloc successfully!$(NC)"; \
		ulimit -v 1048576; \
		valgrind ./test_hd_alloc; \
		rm -f test_hd_alloc; \
	else \
		echo "$(ROJO)Failed to compile test_hd_alloc$(NC)"; \
	fi
	@$(CC) $(CFLAGS) tests/test_open.c $(NAME) -o test_hd_alloc; \
	if [ -f test_hd_alloc ]; then \
		echo "$(VERDE)Compiled test_hd_alloc successfully!$(NC)"; \
		ulimit -v 1048576; \
		valgrind --leak-check=full --track-fds=yes ./test_hd_alloc; \
		rm -f test_hd_alloc; \
	else \
		echo "$(ROJO)Failed to compile test_hd_alloc$(NC)"; \
	fi
	rm -fr .tmp

.PHONY: all clean fclean re

ide-dieg:
	@clear	
	@echo "$(ROJO)██╗██████╗ ███████╗    ██████╗ ██╗███████╗ ██████╗ $(AZUL)         ██╗  ██╗██████╗ "
	@echo "$(ROJO)██║██╔══██╗██╔════╝    ██╔══██╗██║██╔════╝██╔════╝ $(AZUL)         ██║  ██║╚════██╗"
	@echo "$(ROJO)██║██║  ██║█████╗█████╗██║  ██║██║█████╗  ██║  ███╗$(AZUL)         ███████║ █████╔╝"
	@echo "$(ROJO)██║██║  ██║██╔══╝╚════╝██║  ██║██║██╔══╝  ██║   ██║$(AZUL)         ╚════██║██╔═══╝ "
	@echo "$(ROJO)██║██████╔╝███████╗    ██████╔╝██║███████╗╚██████╔╝$(AZUL)              ██║███████╗"
	@echo "$(ROJO)╚═╝╚═════╝ ╚══════╝    ╚═════╝ ╚═╝╚══════╝ ╚═════╝ $(AZUL)              ╚═╝╚══════╝"
	@echo "$(NARANJA)██╗  ██╗ ██████╗ ██████╗ ███╗   ███╗██╗██████╗ ███████╗██╗   ██╗$(VERDE)       ██╗  "
	@echo "$(NARANJA)██║  ██║██╔═══██╗██╔══██╗████╗ ████║██║██╔══██╗██╔════╝██║   ██║$(VERDE)   ██╗ ╚═██╗"
	@echo "$(NARANJA)███████║██║   ██║██████╔╝██╔████╔██║██║██║  ██║█████╗  ██║   ██║$(VERDE)   ╚═╝   ██║"
	@echo "$(NARANJA)██╔══██║██║   ██║██╔══██╗██║╚██╔╝██║██║██║  ██║██╔══╝  ╚██╗ ██╔╝$(VERDE)   ██╗   ██║"
	@echo "$(NARANJA)██║  ██║╚██████╔╝██║  ██║██║ ╚═╝ ██║██║██████╔╝███████╗ ╚████╔╝ $(VERDE)   ╚═╝ ██╔═╝ "
	@echo "$(NARANJA)╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═════╝ ╚══════╝  ╚═══╝  $(VERDE)       ╚═╝  $(NC)"

alloc_title:
	@echo " _  _  ____         __   __    __     __    ___ "
	@echo "/ )( \(    \       / _\ (  )  (  )   /  \  / __)"
	@echo ") __ ( ) D  )____ /    \/ (_/\/ (_/\(  O )( (__ "
	@echo "\_)(_/(____/(____)\_/\_/\____/\____/ \__/  \___)"