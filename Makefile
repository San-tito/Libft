# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguzman <sguzman@student.42barcelo>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 13:10:38 by sguzman           #+#    #+#              #
#    Updated: 2023/10/15 18:09:21 by sguzman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a 
HEADER		= libft.h
SOURCES		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strlen.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_memset.c \
				ft_bzero.c \
				ft_strncmp.c \
				ft_memcpy.c	\
				ft_memmove.c \
				ft_memchr.c \
				ft_strlcpy.c \
				ft_strlcat.c	\
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

SOURCES_B	=	ft_lstnew_bonus.c \
		   		ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
	 			ft_lstlast_bonus.c \
	 			ft_lstadd_back_bonus.c \
	 			ft_lstdelone_bonus.c \
	 			ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

OBJECTS		= $(SOURCES:.c=.o)
OBJECTS_B	= $(SOURCES_B:.c=.o)
CC 			= gcc
RM			= rm -f 
LIB			= ar -rcs
FLAGS		= -Wall -Wextra -Werror
INCS		= ./

all: $(NAME)

%.o:%.c Makefile ${HEADER}
	${CC} ${FLAGS} -I ${INCS} -c $< -o $@

$(NAME): ${OBJECTS}
	${LIB} $(NAME) $(OBJECTS)

bonus: $(NAME) $(OBJECTS_B)
	${LIB} $(NAME) $(OBJECTS_B)

fclean: clean
	$(RM) $(NAME) $(bonus)

clean:
	$(RM) -f $(OBJECTS) $(OBJECTS_B)

re: fclean all

.PHONY: all bonus clean fclean re
