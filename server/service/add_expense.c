void addExpenseToDb(Expense expense){
	char insertIntoExpenseQuery[1000];
	char date[15];
	strncat(date, expense.year, 4);
	strncat(date, "-", 1);
	strncat(date, expense.month, 2);
	strncat(date, "-", 1);
	strncat(date, expense.day, 2); 
	printf("type %s cost %lf date %s", expense.type, expense.cost, date);
	snprintf(insertIntoExpenseQuery, sizeof insertIntoExpenseQuery, "INSERT INTO accounting_db.Expenses(type, cost, date) VALUES('%s', '%f', '%s')"
	         , expense.type, expense.cost, date);
	if((mysql_query(mysql_connection, insertIntoExpenseQuery))) {
		printf("%s\n", mysql_error(mysql_connection));
	}
}

int compareExpenses(Expense expense1, Expense expense2){
	if(strcmp(expense1.type, expense2.type) == 0
	   && strcmp(expense1.month, expense2.month) == 0
	   && strcmp(expense1.year, expense2.year) == 0) {
		return 0;
	}

	return -1;
}

void addExpenseToList(Expense newExpense){
	ExpenseList* current = head;
	while( current != NULL) {
		if( compareExpenses(current->expense, newExpense) == 0 ) {
			return;
		}

		current = current->next;
	}

	ExpenseList* newNode = (ExpenseList*)malloc(sizeof(ExpenseList));
	
	strcpy(newNode->expense.type, newExpense.type);
		newNode->expense.type[strlen(newExpense.type)] = '\0';

	newNode->expense.cost = newExpense.cost;
	
	strcpy(newNode->expense.day, newExpense.day);
		newNode->expense.day[strlen(newExpense.day)] = '\0';	
	
	strcpy(newNode->expense.month, newExpense.month);
		newNode->expense.month[strlen(newExpense.month)] = '\0';
	
	strcpy(newNode->expense.year, newExpense.year);
		newNode->expense.year[strlen(newExpense.year)] = '\0';

	newNode->next = head;
	head = newNode;
}

void addNewExpense(int client_connection_fd){
	Expense newExpense;
	read(client_connection_fd, &newExpense, sizeof(Expense));
	addExpenseToDb(newExpense);
	addExpenseToList(newExpense);
}
