
NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra  -Werror 
PUSH_SWAP_H = push_swap.h 
FILES = first_step.c sort_utils.c utils_list.c utils_ins.c\
			ft_split.c main.c long_sort.c extra_one.c extra_ins.c

OBJS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	  $(CC)  -o $(NAME) $^

%.o : %.c $(PUSH_SWAP_H)
	$(CC) $(CFLAGS)  -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
re : fclean all

.PHONY : clean fclean all
