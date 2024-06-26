# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 15:52:16 by emauduit          #+#    #+#              #
#    Updated: 2024/05/20 13:53:07 by emauduit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                COMPILATION                                   #
################################################################################

NAME = Weapon
CC			= c++
CFLAGS		= -g3 -std=c++98 -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory

################################################################################
#                                  SOURCES                                     #
################################################################################
SRC_DIR = ./

SRC = main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp

################################################################################
#                                  OBJECTS / DEP                                #
################################################################################

OBJ_DIR = obj
OBJ := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

DEPS := $(OBJ:.o=.d)

################################################################################
#                                  COLOR                                       #
################################################################################

PINK = \033[1;95m
RED = \033[0;91m
CYAN = \033[0;96m
MAGENTA = \033[1;35m
RESET = \033[0m

################################################################################
#                                  MAKEFILE                                    #
################################################################################

all: $(NAME) 

$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n$(CYAN)$(NAME) compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ 
	@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)$(RESET)"

################################################################################
#                                  CLEAN / FCLEAN                              #
################################################################################

clean:
		@echo "\n$(RED)Removing: $(OBJ) $(OBJ_DIR) $(DEF_COLOR)$(RESET)\n"
		@rm -rf $(OBJ_DIR)
		@echo "$(RED)Dependencies have been removed.$(RESET)"
		@echo "$(RED)Obj directory has been removed.$(RESET)\n"

fclean: clean
		@rm -f $(NAME)

re: fclean all

.EXTRA_PREREQS:= $(abspath $(lastword $(MAKEFILE_LIST)))
-include $(DEPS)