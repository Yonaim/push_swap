# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 19:40:02 by yeonhkim          #+#    #+#              #
#    Updated: 2022/11/12 15:17:58 by yeonhkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -I./libft/includes -I$(PUSHSWAP_PATH)/includes -I$(CHECKER_PATH)/includes
LDFLAGS			= -L./libft
LDLIBS			= -lft

# ********************************** LIBFT *********************************** #
# **************************************************************************** #

LIBFT			= libft.a

LIBFT_PATH		= ./libft

$(LIBFT):
	make -C $(LIBFT_PATH)
	
# ******************************** PUSH_SWAP ********************************* #
# **************************************************************************** #

PUSHSWAP		= push_swap

PUSHSWAP_PATH	= ./mandatory
PUSHSWAP_SRCS	= \
		/deque/clone_deque.c /deque/closest_edge.c \
		/deque/data.c /deque/dequeue.c \
		/deque/destroy_deque.c /deque/distance.c \
		/deque/dq_max.c /deque/dq_min.c \
		/deque/enqueue.c /deque/is_sorted_state.c \
		/deque/newelem.c /instruction/push.c \
		/instruction/rotate.c /instruction/rrotate.c \
		/instruction/swap.c /ps_parse_argument.c \
		/ps_print_solution.c /ps_solve.c \
		/push_swap.c /sort/sort_deviation_guarant.c \
		/sort/sort_five_or_below.c /sort/sort_greedy_1.c \
		/sort/sort_greedy_2.c /utils/exec_cmd_repeat.c \
		/utils/exit_by_error.c /utils/init_ps_state.c \
		/utils/lstadd_new_back.c \
		/utils/max.c /utils/min.c

$(PUSHSWAP): $(addprefix $(PUSHSWAP_PATH)/srcs, $(PUSHSWAP_SRCS:.c=.o))
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
$(addprefix $(PUSHSWAP_PATH)/srcs, $(PUSHSWAP_SRCS:.c=.o)):

# ********************************* CHECKER ********************************** #
# **************************************************************************** #

CHECKER			= checker

CHECKER_PATH	= ./bonus
CHECKER_SRCS  	= \
		/checker_bonus.c \
		/deque/clone_deque_bonus.c \
		/deque/dequeue_bonus.c \
		/deque/enqueue_bonus.c \
		/deque/is_sorted_state_bonus.c \
		/deque/newelem_bonus.c \
		/instruction/push_bonus.c \
		/instruction/rotate_bonus.c \
		/instruction/rrotate_bonus.c \
		/instruction/swap_bonus.c \
		/ps_parse_argument_bonus.c \
		/utils/exit_by_error_bonus.c \
		/utils/lstadd_new_back_bonus.c 

$(CHECKER): $(addprefix $(CHECKER_PATH)/srcs, $(CHECKER_SRCS:.c=.o))
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@
$(addprefix $(CHECKER_PATH)/srcs, $(CHECKER_SRCS:.c=.o)):

# ******************************** MAKE RULES ******************************** #
# **************************************************************************** #

all :
	make -C $(LIBFT_PATH)
	make $(PUSHSWAP)

bonus:
	make -C $(LIBFT_PATH)
	make $(CHECKER)

clean :
	make -C $(LIBFT_PATH) clean
	rm -f $(addprefix $(PUSHSWAP_PATH)/srcs, $(PUSHSWAP_SRCS:.c=.o)) $(addprefix $(CHECKER_PATH)/srcs, $(CHECKER_SRCS:.c=.o))

fclean :
	make -C $(LIBFT_PATH) fclean
	rm -f $(PUSHSWAP) $(CHECKER) $(addprefix $(PUSHSWAP_PATH)/srcs, $(PUSHSWAP_SRCS:.c=.o)) $(addprefix $(CHECKER_PATH)/srcs, $(CHECKER_SRCS:.c=.o))

re : 
	make fclean
	make all

test100 :
	seq 100 | sort -R | xargs ./push_swap | wc -l

test500 :
	seq 500 | sort -R | xargs ./push_swap | wc -l

.PHONY : all bonus clean fclean re test100 test500
