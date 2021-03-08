CC = gcc
CFLAG = -Wall -Wextra -Werror

TARGET = libftprintf.a
SRC = ft_printf_main.c ft_set_struct.c ft_percent.c ft_print_arr.c ft_put_arr.c ft_char.c ft_num.c ft_ptr.c ft_put_arr_n.c ft_put_arr_s.c ft_set_struct.c ft_str.c
OBJ = $(SRC:.c=.o)

$(NAME) : all

all : $(TARGET)

$(TARGET) : $(OBJ)
	ar rcv $(TARGET) $(OBJ)

%.o : %.c
	$(CC) $(CFLAG) -c $<

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(TARGET)

re : fclean all

.PHONY : all clean fclean re
