void printAllExpenses(int socket_fd){
	Expense expense;
	printf("\nExpenses:\n");
	while(1) {
		read(socket_fd, &expense, sizeof(Expense));
		if(strcmp(expense.type, "end") == 0) {
			break;
		}

		printf("Type: %s cost %.2lf, payed on: %s-%s-%s\n", expense.type, expense.cost, expense.day, expense.month, expense.year);
	}
	printf("\n");
}
