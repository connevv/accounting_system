void deleteExpenseFromDb(Expense expenseToRemove) {
	char deleteExpenseQuery[500];
	char date[15];
	strncat(date, expenseToRemove.year, 4);
	strncat(date, "-", 1);
	strncat(date, expenseToRemove.month, 2);
	strncat(date, "-", 1);
	strncat(date, expenseToRemove.day, 2);
	snprintf(deleteExpenseQuery, sizeof(deleteExpenseQuery), "DELETE FROM Expenses WHERE type='%s' AND date='%s'", expenseToRemove.type, date);
	if ((mysql_query(mysql_connection, deleteExpenseQuery))) {
		printf("%s\n", mysql_error(mysql_connection));
	}
	printf("Expense : %s payed on date %s successfully deleted from database \n", expenseToRemove.type, date);
}



void deleteExpenseFromList(Expense expenseToRemove) {
	ExpenseList* current = head;
	ExpenseList* previous = current;
	ExpenseList* nodeToDelete = NULL;
	while (current != NULL) {
		if( compareExpenses(current->expense, expenseToRemove) == 0 ) 
		{	
		
			nodeToDelete = current;
			break;
		}

		previous = current;
		current = current->next;
	}

	if (nodeToDelete == head) {
		head = nodeToDelete->next;
	}
	else {
		previous->next = nodeToDelete->next;
	}

	if (nodeToDelete != NULL) {
		free(nodeToDelete);
	}

	printf("Expense : %s successfully deleted from list \n", expenseToRemove.type);
}

void deleteExpense(int client_connection_fd) {
	Expense expenseToDelete;
	read(client_connection_fd, &expenseToDelete, sizeof(Expense));

	deleteExpenseFromDb(expenseToDelete);
	deleteExpenseFromList(expenseToDelete);
}

