# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 21:03:37 by marvin            #+#    #+#              #
#    Updated: 2024/06/22 18:34:23 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is a minimal set of ANSI/VT100 color codes
_END=\033[0;0m
_BOLD=\033[0;1m

# Colors
_GREY=\033[0;30m
_GREEN=\033[0;32m
_BLUE=\033[0;34m

# Color test
_ROSE=\x1b[38;5;213m
_NEW_BLUE=\x1b[38;5;80m
_GREEN_BOLD=\033[1;32m
_LIGHT_GREY=\x1b[38;5;242m

MAKEFLAGS += --no-print-directory
OPTIONS_PRINTED = /tmp/options_printed_$(shell echo $$USER)

SRC = \
	Account.cpp \
	tests.cpp

OBJ_DIR = obj
OBJ = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

NAME = bank
RM = rm -rf
CC = c++
CFLAGS = -Wall -Wextra -std=c++98 #-Werror
INC = -I./headers

all : $(NAME)

print_options : $(OPTIONS_PRINTED)

$(OPTIONS_PRINTED) :
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_ROSE)Compiling options$(_END) :  $(CC) $(CFLAGS)\""
	@ /bin/bash -c "echo"
	@ touch $(OPTIONS_PRINTED)

$(NAME) : $(OPTIONS_PRINTED) $(OBJ_DIR) $(OBJ)
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_NEW_BLUE)Linking files creating binary $(NAME)$(_END)\""
	@ /bin/bash -c "echo -e \"$(CC) $(CFLAGS) $(notdir $(OBJ))\""
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@ /bin/bash -c "echo"
	@ /bin/bash -c "echo -e \"$(_GREEN_BOLD)[DONE]$(_END)\"" 

$(OBJ_DIR) :
	@ mkdir -p $@

$(OBJ_DIR)/%.o: %.cpp
	@ /bin/bash -c "printf \"$(_BLUE)Compiling$(_END) %-21s --> %-21s\n\" $(notdir $<) $(notdir $@)"
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@ /bin/bash -c "echo -e \"$(_LIGHT_GREY)Cleaning object files$(_END)\""
	@ $(RM) $(OBJ_DIR)
	@ $(RM) $(OPTIONS_PRINTED)

fclean : clean
	@ /bin/bash -c "echo -e \"$(_LIGHT_GREY)Cleaning binary$(_END)\""
	@ $(RM) $(NAME)

re : fclean all
