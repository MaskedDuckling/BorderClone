NAME = dark_zombie

CC = g++

CFLAGS = -Wall -Wextra -Werror

SRC = main.cpp		\
	Perso.cpp		\
	Vector.cpp		\
	Game.cpp

SRCS		= $(addprefix srcs/, $(SRC))

OBJS		= $(addprefix objs/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 $(CFLAGS) -o $(NAME)

objs/%.o:	srcs/%.cpp
			$(CC) $(CFLAGS) -o $@ -c $<
#.c.o:
#	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

po: all clean

re: fclean all

.PHONY: all re clean fclean
