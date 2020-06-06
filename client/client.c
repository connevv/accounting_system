#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080

#include "/home/jovan/Desktop/project-spr/structures/expense.h"
#include "prototypes.h"

#include "/home/jovan/Desktop/project-spr/client/service/add_expense_impl.c"
#include "/home/jovan/Desktop/project-spr/client/service/delete_expense_impl.c"
#include "/home/jovan/Desktop/project-spr/client/service/biggest_expense_impl.c"
#include "/home/jovan/Desktop/project-spr/client/service/monthly_expense_impl.c"
#include "/home/jovan/Desktop/project-spr/client/service/print_expenses.c"
#include "/home/jovan/Desktop/project-spr/client/service/client_tcp_impl.c"

int main(){
	int socket_fd = createSocket();
	connectToServer(socket_fd);

	serverComunicationService(socket_fd);

	close(socket_fd);
	return 0;
}
