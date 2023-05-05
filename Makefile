# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 20:44:34 by dcarvalh          #+#    #+#              #
#    Updated: 2023/05/05 22:39:24 by dcarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread #-fsanitize=address

SRCS =	libs/gc/gc.c libs/gc/gc_utils.c \
		libs/strings/strings.c libs/strings/strings_utils.c libs/strings/strings_utils1.c \
		parsing.c message.c \
		sleep.c eat.c\
		error.c utils.c \
		philo.c

B_SRCS = 

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

C_RED = \033[0;31m
C_GREEN = \033[1;92m
C_RESET = \033[0m
C_PURPLE = \033[0;35m
C_RED = \033[0;31m
BG_YELLOW = \x1b[43m

SRCS := $(addprefix srcs/, $(SRCS))
B_SRCS := $(addprefix srcs/bonus/, $(B_SRCS))

echo = /bin/echo -e

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -Iincs
	@$(echo) "$(C_GREEN) [OK]   $(C_PURPLE) Compiling:$(C_RESET)" $<

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@$(echo) "$(C_GREEN) [OK]   $(C_PURPLE) Compiling:$(C_RESET)" $(NAME)
	@$(echo) "$(C_GREEN)\tCompiled $(NAME)$(C_RESET)"
	
all : $(NAME)

bonus : $(B_OBJS) 
	@$(CC) $(B_OBJS) -o $(NAME)
	@$(echo) "$(C_GREEN) [OK]   $(C_PURPLE) Compiling:$(C_RESET)" $(NAME)
	@$(echo) "$(C_GREEN)\tCompiled $(NAME)$(C_RESET)"

clean:
	@rm -f $(OBJS) $(B_OBJS)
	@$(echo) "$(C_RED)\tRemoved object files$(C_RESET)"
	
fclean: clean
	@rm -f $(NAME) *.txt
	@$(echo) "$(C_RED)\tRemoved $(NAME)$(C_RESET)"
	
re: fclean all
	
sanitize: $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) -g -fsanitize=address

b_sanitize : $(B_OBJS)
	@$(CC) $(B_OBJS) -o $(NAME) -g -fsanitize=address
norm_M:
	@$(echo) "$(C_RED)$(BG_YELLOW)[Norminette]$(C_RESET)"
	@$(shell (norminette $(SRCS) incs/*> norm.txt))
	@if [ $(shell (< norm.txt wc -l)) -eq $(shell (< norm.txt grep "OK" | wc -l)) ] ;then \
		$(echo) "$(C_PURPLE)[Mandatory]: $(C_GREEN) [OK]$(C_RESET)" ; \
	else \
		$(echo) "$(C_PURPLE)[Mandatory]: $(C_RED) [KO]$(C_RESET)"; \
		< norm.txt cat | grep -v "OK" | grep --color=always -e "^" -e "Error:"; \
	fi ;
	@rm -f norm.txt

norm : norm_M
	@$(shell (norminette $(B_SRCS) incs/$(NAME)_bonus.h > norm.txt))
	@if [ $(shell (< norm.txt wc -l)) -eq $(shell (< norm.txt grep "OK" | wc -l)) ] ;then \
		$(echo) "$(C_PURPLE)[BONUS]: $(C_GREEN) [OK]$(C_RESET)" ; \
	else \
		$(echo) "$(C_PURPLE)[BONUS]: $(C_RED) [KO]$(C_RESET)"; \
		< norm.txt cat | grep -v "OK" | grep --color=always -e "^" -e "Error:"; \
	fi ;
	@rm -f norm.txt

git : $(SRCS)
	@git add $(SRCS)
	@$(echo) "$(C_GREEN) SRCS added to git $(C_RESET)" $(NAME)
	@git commit -am "make commit"
	@$(echo) "$(C_PURPLE) SRCS commited $(C_RESET)" $(NAME)
	@git push origin master
	@$(echo) "$(C_GREEN) PUSHED $(C_RESET)" $(NAME)

	