Expense initializeExpense() {
	Expense expense;
	char type[20];
	char cost[10];
	char day[10];
	char month[10];
	char year[10];
	fflush(stdin);
	printf("\nEnter type of expense: ");
	scanf("%s", type);
	strcpy(expense.type, type);
	expense.type[strlen(type)] = '\0';
	(expense.type)[strcspn(expense.type, "\n")] = '\0';

	printf("\nEnter cost of the expense: ");
	scanf("%s", cost);
	expense.cost = atof(cost);

	printf("\nEnter day of payment: ");
	scanf("%s", day);
	strcpy(expense.day, day);
	expense.day[strlen(day)] = '\0';
	(expense.day)[strcspn(expense.day, "\n")] = '\0';


	printf("\nEnter month of payment: ");
	scanf("%s", month);
	strcpy(expense.month, month);
	expense.month[strlen(month)] = '\0';
	(expense.month)[strcspn(expense.month, "\n")] = '\0';

	
	printf("\nEnter year of payment: ");
	scanf("%s", year);
	strcpy(expense.year, year);
	expense.year[strlen(year)] = '\0';
	(expense.year)[strcspn(expense.year, "\n")] = '\0';

	printf("\n");
	return expense;
}

void addNewExpense(int socket_fd) {
	
	Expense newExpense = initializeExpense();
	write(socket_fd, &newExpense, sizeof(Expense));
	printf("Expense : %s payed on :%s-%s-%s added successfully.\n", newExpense.type, newExpense.day, newExpense.month, newExpense.year);
}
