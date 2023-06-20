# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:20:05 by seojulee          #+#    #+#              #
#    Updated: 2023/05/19 14:57:38 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror $(INFLAGS)
INFLAGS		= -I $(INCS_DIR) -I ${HOME}/.brew/opt/readline/include
LIBFT_FLAGS	= -L./libft -lft
RL_FLAGS	= -lreadline -L${HOME}/.brew/opt/readline/lib

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs/

SRCS		= main \
			  shell/intro \
			  shell/shell \
			  shell/signal \
			  shell/utils \
			  debug/debug \
			  builtins/builtins \
			  builtins/builtins_cd \
			  builtins/builtins_echo \
			  builtins/builtins_env \
			  builtins/builtins_exit \
			  builtins/builtins_export \
			  builtins/builtins_pwd \
			  builtins/builtins_unset \
			  builtins/builtins_utils \
			  builtins/builtins_utils_merge \
			  execute/execute \
			  execute/execute_pipe \
			  execute/execute_redir \
			  execute/execute_simple \
			  execute/execute_process \
			  execute/execute_process_utils \
			  execute/execute_heredoc \
			  execute/execute_utils \
			  execute/execute_cmd \
			  expand/expand \
			  expand/expand_quote \
			  expand/expand_utils \
			  expand/expand_backslash \
			  expand/parse_dollar \
			  hashtable/hashtable \
			  hashtable/hash_function \
			  hashtable/hashtable_find \
			  hashtable/hashtable_print \
			  hashtable/hashtable_insert \
			  hashtable/hashtable_destroy \
			  hashtable/hashtable_delete \
			  hashtable/hashtable_merge \
			  hashtable/hashtable_len \
			  lexer/lexer \
			  lexer/lexer_blank \
			  lexer/lexer_delete \
			  lexer/lexer_divide \
			  lexer/lexer_eof \
			  lexer/lexer_general \
			  lexer/lexer_new_token \
			  lexer/lexer_quote \
			  lexer/lexer_redirect \
			  lexer/lexer_str \
			  lexer/lexer_destroy \
			  lexer/lexer_utils_01 \
			  lexer/lexer_utils_02 \
			  parser/parser \
			  parser/parser_command_pipe \
			  parser/parser_command_redir \
			  parser/parser_simple_command \
			  tree/tree_new_node \
			  tree/tree_destroy \

SRCS_A		= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS)))
OBJS		= $(SRCS_A:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
			@ $(MAKE) -C ./libft
			@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(RL_FLAGS)

%.o 		: %.c
			@ $(CC) $(CFLAGS) -c $< -o $@

clean		:
			@ rm -rf $(OBJS)
			@ $(MAKE) -C ./libft clean

fclean		: clean
			@ rm -rf ./libft/libft.a
			@ rm -rf $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
