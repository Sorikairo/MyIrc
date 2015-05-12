##
## Makefile for make in /home/fouhet_k/Perso/PSU_2014_myirc
## 
## Made by kevin fouhety
## Login   <fouhet_k@epitech.net>
## 
## Started on  Fri Apr 10 11:43:18 2015 kevin fouhety
## Last update Sun Apr 12 22:08:12 2015 Thomas CRUVEILHER
##

CC		=	cc -g3

RM		=	rm -f

PATH_CLIENT	=	Sources/client

PATH_SERVER	=	Sources/server

PATH_UTILS	=	Sources/utils

NAME_CLIENT	=	client

NAME_SERVER	=	server

SRC_CLIENT	=	$(PATH_CLIENT)/main.c			\
			$(PATH_CLIENT)/func_channel.c 		\
			$(PATH_CLIENT)/func_client.c 		\
			$(PATH_CLIENT)/func_quit.c		\
			$(PATH_CLIENT)/parsing_addr.c		\
			$(PATH_UTILS)/list_func.c		\
			$(PATH_UTILS)/check_content.c		\
			$(PATH_UTILS)/buffer.c			\
			$(PATH_UTILS)/utils.c			\

SRC_SERVER	=	$(PATH_SERVER)/user.c 			\
			$(PATH_SERVER)/server.c 		\
			$(PATH_SERVER)/utils.c 			\
			$(PATH_SERVER)/exec_function.c 		\
			$(PATH_SERVER)/list_server_func.c 	\
			$(PATH_SERVER)/channel.c 		\
			$(PATH_SERVER)/function_to_execute.c  	\
			$(PATH_SERVER)/get_functions.c  	\
			$(PATH_UTILS)/check_content.c		\
			$(PATH_UTILS)/buffer.c			\
			$(PATH_UTILS)/utils.c 			\

CFLAGS		=	-Wextra -Wall -Werror -ansi -pedantic -I./Includes/

OBJ_CLIENT	=	$(SRC_CLIENT:.c=.o)

OBJ_SERVER	=	$(SRC_SERVER:.c=.o)



all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT)

$(NAME_SERVER) : $(OBJ_SERVER)
	$(CC) -o $(NAME_SERVER) $(OBJ_SERVER)

clean:
	$(RM) $(OBJ_CLIENT)
	$(RM) $(OBJ_SERVER)

fclean: clean
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re
