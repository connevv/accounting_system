#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


#define PORT 8080
#define DESTINATION_NAME_LENGTH 50

#include "/home/jovan/Desktop/project-spr/structures/expense.h"
#include "/home/jovan/Desktop/project-spr/structures/expenses_list.h"


ExpenseList* head;

#include "prototypes.h"
MYSQL* mysql_connection;
	
#include "/home/jovan/Desktop/project-spr/server/service/add_expense.c"
#include "/home/jovan/Desktop/project-spr/server/service/remove_expense.c"
#include "/home/jovan/Desktop/project-spr/server/service/print_expenses.c"
#include "/home/jovan/Desktop/project-spr/server/service/biggest_expense.c"
#include "/home/jovan/Desktop/project-spr/server/service/monthly_expense.c"

#include "/home/jovan/Desktop/project-spr/server/database/load_expenses.c"
#include "/home/jovan/Desktop/project-spr/server/database/database_connection.c"

#include "/home/jovan/Desktop/project-spr/server/communication/server_tcp_impl.c"

int main(){
	connectToDatabase();

	int socket_fd = createSocket();

	struct sockaddr_in serverAddress = initializeServer();

	bindServerToLocalHost(socket_fd, serverAddress);
	makeServerListen(socket_fd);

	int client_connection_fd = connectToClient(socket_fd);

	clientComunicationService(client_connection_fd);


	close(socket_fd);
	mysql_close(mysql_connection);
	return 0;
}
