NAME	=	philo_bonus

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -fsanitize=address
# FLAGS	=	-Wall -Wextra -Werror -fsanitize=thread

INCL	= 	./inc/

CFLAGS	=	$(FLAGS) -lpthread -I $(INCL)

PATH_SRC	=	./src/

PATH_LIFE	=	$(PATH_SRC)life/

PATH_UTILS	=	$(PATH_SRC)utils/

PATH_OBJ	=	./object_files/

FILE_SRC	=	main.c \

FILE_LIFE	=	life.c

FILE_UTILS	=	init.c \
				parser.c \
				routine.c \
				validator.c \
				utils.c


HEAD_FILE	=	./inc/philo_bonus.h\
				./inc/utils.h\
				./inc/struct.h\
				./inc/life.h\

SRC_PH	=	$(addprefix $(PATH_SRC), $(FILE_SRC))\
			$(addprefix $(PATH_UTILS), $(FILE_UTILS)) \
			$(addprefix $(PATH_LIFE), $(FILE_LIFE))

OBJ		=	$(patsubst $(PATH_SRC)%, $(PATH_OBJ)%, $(SRC_PH:.c=.o))

.PHONY			:	all clean fclean re
.ONESHELL		:

all				:	$(NAME) $(HEAD_FILE)

$(PATH_OBJ)%.o	:	$(PATH_SRC)%.c $(HEAD_FILE)
	@if ! [ -d ./object_files ] ; then \
		mkdir object_files ; \
		mkdir object_files/life ; \
		mkdir object_files/utils ; \
	fi 
	@$(CC) $(FLAGS) -c $< -o $@
	@echo FILE COLLECTED $@

$(NAME)			:	 $(OBJ) $(HEAD_FILE) $(SRC_PH)
	@$(CC) $(CFLAGS) $(PATH_OBJ)*.o $(PATH_OBJ)utils/*.o $(PATH_OBJ)life/*.o -o $(NAME)

clean			:
	@rm -rf $(PATH_OBJ)

fclean			:	clean
	@rm -rf $(NAME)

re				:	fclean all
