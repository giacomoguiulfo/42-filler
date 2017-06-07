# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 07:02:04 by gguiulfo          #+#    #+#              #
#    Updated: 2017/06/07 10:13:22 by gguiulfo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= filler

CC 		:= gcc
CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -I includes -I libft/includes
LDFLAGS += -L libft/ -lft

LIBFT	:= libft/libft.a

FILES	:= filler heatmap main map small_filler utils debug_filler

OBJDIR	:= obj/
SRCDIR	:= src/

SRC = $(addsuffix .c, $(FILES))
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

MAX			:=	$(words $(OBJ))
n			:=	x
increment	=	$1 x
COUNTER		=	$(words $n)$(eval n := $(call increment,$n))

.PHONY = all clean fclean re obj libft

all: obj libft $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@printf "\r\e[32mCompiling...(%d/%d)\e[0m" $(COUNTER) $(MAX)
	@$(CC) $(CFLAGS) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ)
	@printf "\r\e[32mCompiling...(%d/%d)[DONE]\n\e[0m" $(MAX) $(MAX)
	@$(CC) $(LDFLAGS) -o $@ $^
	@printf "\e[32mCompiled Executable\e[0m\n"

clean:
	@rm -rf $(OBJDIR)
	@make -C libft clean
	@printf "\e[32mRemoved Object Files\e[0m\n"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@printf "\e[32mRemoved Executable\e[0m\n"

re: fclean all
