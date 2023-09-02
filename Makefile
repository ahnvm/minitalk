SRCSERVER = server.c utils.c

SRCCLIENT = client.c utils.c

SRCBONUSCLIENT = ./minitalk_bonus/client_bonus.c ./minitalk_bonus/utils_bonus.c

SRCBONUSSERVER = ./minitalk_bonus/server_bonus.c ./minitalk_bonus/utils_bonus.c

NAMECLIENT = client

NAMESERVER = server

NAMEBONUSCLIENT = bonus_client

NAMEBONUSSERVER = bonus_server

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror


all : $(NAMECLIENT) $(NAMESERVER)

$(NAMECLIENT):
	$(CC) $(CFLAGS) $(SRCCLIENT) -o $(NAMECLIENT)

$(NAMESERVER):
	$(CC) $(CFLAGS) $(SRCSERVER) -o $(NAMESERVER)
	

bonus : $(NAMEBONUSCLIENT) $(NAMEBONUSSERVER)

$(NAMEBONUSCLIENT):
	$(CC) $(CFLAGS) $(SRCBONUSCLIENT) -o $(NAMEBONUSCLIENT)

$(NAMEBONUSSERVER):
	$(CC) $(CFLAGS) $(SRCBONUSSERVER) -o $(NAMEBONUSSERVER)  


clean: 
	$(RM) $(NAMECLIENT) $(NAMESERVER) $(NAMEBONUSCLIENT) $(NAMEBONUSSERVER)

fclean: clean

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus