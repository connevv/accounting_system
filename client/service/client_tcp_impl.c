void printMenu(){
	printf("\n");
	printf("1. Add new Expense\n");
	printf("2. Delete Expense\n");
	printf("3. Print all expenses\n");
	printf("4. Find biggest expense\n");
	printf("5. Find monthly expense\n");
	printf("6. Exit\n");
	printf("\n");
}

int createSocket(){
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	} else{
		printf("Socket successfully created..\n");
	}
	return socket_fd;
}

void connectToServer(int socket_fd){
	struct sockaddr_in serverAddress;
	bzero(&serverAddress, sizeof(serverAddress));

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = 8080;

	if (connect(socket_fd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) != 0) {
		printf("connection with the server failed...\n");
		exit(0);
	}       else{
		printf("connected to the server..\n");
	}

}

void serverComunicationService(int socket_fd){
	int n;
	int option;
	char optionString[2];
	while(1) {
		printf("\nEnter one of the below options:\n");
		printMenu();
		scanf("%s", optionString);
		option = atoi(optionString);
		if(write(socket_fd, &option, sizeof(int))<0){
		printf("ERROR WRITING TO SERVER");		
		}

		switch (option) {
		case 1: addNewExpense(socket_fd); break;
		case 2: deleteExpense(socket_fd); break;
		case 3: printAllExpenses(socket_fd); break;
		case 4: printBiggestExpense(socket_fd); break;
		case 5: printMonthlyExpense(socket_fd); break;
		case 6: printf("Program exit"); break;
		default: printf("Option does not exist"); break;
		}
		if( option == 6) {
			printf("Client exit");
			break;
		}
	}
}
