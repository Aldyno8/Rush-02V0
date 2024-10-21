SRC = main.c files.c find_number_in_dic.c string.c string1.c
CFLAGS += -Werror -Wall -Wextra
NAME = rush-02
$(NAME): $(SRC)
	cc -o $(NAME) $(SRC)
$fclean:
	rm -f $(NAME)
