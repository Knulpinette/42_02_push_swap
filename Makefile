# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osurcouf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 13:51:10 by osurcouf          #+#    #+#              #
#    Updated: 2021/08/04 13:51:13 by osurcouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*-🦕-*- Make Push_Swap -*-🦕-*- 

NAME	= push_swap

# -*- Definitions of variables -*-

SRCS_DIR	= srcs
SRCS		= ${addprefix ${SRCS_DIR}/,${SRCS_FIND}}
SRCS_FIND	= ${shell find . -type f \( -wholename "./srcs/*.c" -not -wholename "./ft_*bonus.c" -not -wholename "./libft/ft_*.c" \) | cut -d'/' -f3-}
SRCS_BONUS	= ${addprefix ${SRCS_DIR}/,${SRCS_BFIND}}
SRCS_BFIND	= ${shell find . -type f \( -wholename "./srcs/*.c" -not -wholename "./libft/ft_*.c" \) | cut -d'/' -f3-}

OBJS_DIR	= objs
OBJS		= ${addprefix ${OBJS_DIR}/,${SRCS_FIND:.c=.o}}
OBJS_BONUS	= ${addprefix ${OBJS_DIR}/,${SRCS_BFIND:.c=.o}}

INCLUDES	= -Iincludes

LIBFT_DIR	= libft
LIBFT_LIB	= -Llibft -lft

MEM_LEAK_CHECK = -L42_memleak_check/ -lmlc

CC			= gcc
RM			= rm -f
MAKE		= make
CFLAGS 		= -Wall -Wextra -Werror -fsanitize=address -g

# Colors

GRAY		= \e[1;30m
GREEN 		= \e[1;32m
DARK_GREEN	= \e[0;32m
YELLOW		= \e[1;33m
BLUE		= \e[1;34m
PURPLE		= \e[1;35m
CYAN		= \e[1;36m
WHITE		= \e[1;37m
NORMAL		= \e[0;37m
END			= \e[0m

# -*- The Rules -*-

#	Implicit rules

# Create and compile objects files in a dedicated folder
${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c 
			@mkdir -p objs
			@mkdir -p objs/stack_lists
			@mkdir -p objs/utils
			@mkdir -p objs/stack_actions
			@mkdir -p objs/algorithm
			@${CC} ${CFLAGS} ${INCLUDES} -O3 -c $< -o $@

#	Active rules

all:		${NAME} test

# Make libft + compile push_swap
${NAME}:	${OBJS}
			${MAKE} bonus -C ${LIBFT_DIR}
			$(CC) ${CFLAGS} ${INCLUDES} ${OBJS} ${LIBFT_LIB} -o $(NAME)

test:		${NAME}
			@printf "\n	📚 [${PURPLE}INSTRUCTIONS${END}] 📚\n"
			@printf "\n🦕🍭	${YELLOW}To show stacks actions details${END}\n"
			@printf "./push_swap ${GRAY}NUMBERS${END} | ./checker -v ${GRAY}NUMBERS${END}\n"
			@printf "\n"
			@printf "\n🦕🍭	${YELLOW}To test the program${END}\n"
			@printf "${GRAY}bash tester_linux.sh${END} [random numbers between] ${GRAY}1 ${END}[&] ${GRAY}500 ${END}[in nb of moves max] ${GRAY}5500${END}\n"
			@printf "\n"
			@printf "\n🦕🍭	${YELLOW}Copy/paste to use visualizer (the first gray part is only for WSL)${END}\n"
			@printf "${GRAY}DISPLAY=\$$(cat /etc/resolv.conf | grep nameserver | awk '{print \$$2}'):0${END} python3 pyviz.py ${GRAY}`ruby -e "puts (0..500).to_a.shuffle.join(' ')"` ${END}"
			@printf "\n\n"

bonus:		${NAME} 

#	Cleaning rules

clean:
			${MAKE} clean -C ${LIBFT_DIR}
			${RM} ${OBJS} ${OBJS_BONUS}
			rm -rf objs

fclean:		clean
			${MAKE} fclean_no_clean -C ${LIBFT_DIR}
			${RM} ${NAME}

re:			fclean all

.PHONY:		libft all clean fclean re

