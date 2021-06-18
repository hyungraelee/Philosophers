NAME = philo_bonus
CC = gcc
CFLAGS = -lpthread #-Wall -Wextra -Werror
CFLAGS = -g3 #-fsanitize=address
# ifeq ($(DEBUG),true)
# 	CFLAGS += -g
# endif

SRCS_DIR =	./srcs	\
			./srcs/utils
OBJS_DIR = ./objs
INC_DIR = ./includes
SRCS =	./srcs/main.c	\
		./srcs/parents.c	\
		./srcs/child.c	\
		./srcs/routine.c	\
		./srcs/tools.c	\
		./srcs/print.c	\
		./srcs/utils/ft_atoi.c	\
		./srcs/utils/ft_putchar_fd.c	\
		./srcs/utils/ft_putendl_fd.c	\
		./srcs/utils/ft_putnbr_fd.c		\
		./srcs/utils/ft_putstr_fd.c		\
		./srcs/utils/ft_strlen.c


OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
vpath %.c $(SRCS_DIR)
RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR) -c $^

clean :
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
