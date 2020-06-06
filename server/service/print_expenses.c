void printExpenses(int client_connection_fd){
	ExpenseList* current = head;

	while(current != NULL) {
		write(client_connection_fd, &(current->expense), sizeof(Expense));
		current = current->next;
	}

	char endString[10];
	strcpy(endString, "end");
	write(client_connection_fd, &endString, sizeof(endString));
}
