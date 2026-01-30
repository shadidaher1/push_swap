# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdaher <sdaher@student.42beirut.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 13:20:26 by sdaher            #+#    #+#              #
#    Updated: 2025/11/12 13:32:34 by sdaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			=  ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memchr.c ft_memcpy.c ft_memset.c ft_strlcat.c ft_strlen.c ft_strnstr.c ft_strdup.c ft_substr.c\
			ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memcmp.c ft_memmove.c ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_toupper.c ft_tolower.c ft_calloc.c\
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
			  
BONUS		= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
				ft_lstmap_bonus.c

BONUS_OBJ	= $(BONUS:.c=.o)

OBJ			= $(SRC:.c=.o)

RM			= rm -f

# ==== RULES ================================================================= #

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# ==== PHONY ================================================================= #

.PHONY: all clean fclean re bonus
