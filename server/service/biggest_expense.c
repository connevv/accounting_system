void getBiggestExpense (int client_connection_fd) {
	ExpenseList* biggest = head;
	ExpenseList* current = head->next;
	
	while (current != NULL) {
	if (current->expense.cost > biggest->expense.cost) {
		biggest = current;
		} 	
	
	current = current->next;
	}
	
	write(client_connection_fd, &biggest->expense, sizeof(biggest->expense));

}
