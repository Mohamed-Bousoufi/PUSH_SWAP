
NAME = push_swap
NAME_BONUS = checker
CC = cc 
CFLAGS = -Wall -Wextra  -Werror 
PUSH_SWAP_H = push_swap.h 

PUSH_SWAP_BONUS_H = bonus/push_swap_bonus.h 

FILES = first_step.c sort_utils.c utils_list.c utils_ins.c\
			ft_split.c main.c long_sort.c extra_one.c extra_ins.c\
			extra_sort.c

FILES_BONUS = bonus/constr.c bonus/main.c bonus/utils_list_bonus.c\
				bonus/split_bonus.c bonus/extra_bonus.c bonus/first_step_bonus.c\
				bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c\
				bonus/utils_ins_bonus.c bonus/extra_ins_bonus.c

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) -o $(NAME_BONUS) $^ 

$(NAME) : $(OBJS)
	  $(CC)  -o $(NAME) $^

%.o : %.c $(PUSH_SWAP_H) $(PUSH_SWAP_BONUS_H)
	$(CC) $(CFLAGS)  -c $< -o $@
clean :
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)
re : fclean all

.PHONY : clean fclean all
