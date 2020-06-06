void getMonthlyExpense (int client_connection_fd) {
	ExpenseList* current = head;

	double monthlyCost = 0;
	while (current != NULL) {
		monthlyCost += current->expense.cost;
	current = current->next;
	}

	write(client_connection_fd, &monthlyCost, sizeof(double));

}
