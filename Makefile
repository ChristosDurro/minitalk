SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = ${SRCS_SERVER:.c=.o}
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

SERVER_NAME = server
CLIENT_NAME = client

LIBFT = libft
LIBFT_LIB = libft/libft.a

HEADER = minitalk.h

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: ${SERVER_NAME} ${CLIENT_NAME}

%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${SERVER_NAME}: ${OBJS_SERVER}
	make -C ${LIBFT}
	${CC} ${CFLAGS} ${OBJS_SERVER} ${LIBFT_LIB} -o ${SERVER_NAME}

${CLIENT_NAME}: ${OBJS_CLIENT}
	${CC} ${CFLAGS} ${OBJS_CLIENT} ${LIBFT_LIB} -o ${CLIENT_NAME}

clean:
	make -C ${LIBFT} clean
	rm -f ${OBJS_SERVER} ${OBJS_CLIENT}

fclean: clean
	make -C ${LIBFT} fclean
	rm -f ${SERVER_NAME} ${CLIENT_NAME}

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus