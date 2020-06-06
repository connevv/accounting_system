void deleteExpense(int socket_fd){
	Expense deleteExpense;	
	char type[20];
	char cost[10];
	char day[10];
	char month[10];
	char year[10];
        
	printf("\n");
			
	printf("\nEnter type of expense\n");
	scanf("%s", type);
	strcpy(deleteExpense.type, type);
	deleteExpense.type[strlen(type)] = '\0';
	(deleteExpense.type)[strcspn(deleteExpense.type, "\n")] = '\0';

	printf("\nEnter cost of the expense\n");
	scanf("%s", cost);
	deleteExpense.cost = atof(cost);

	printf("\nEnter day of payment\n");
	scanf("%s", day);
	strcpy(deleteExpense.day, day);
	deleteExpense.day[strlen(day)] = '\0';
	(deleteExpense.day)[strcspn(deleteExpense.day, "\n")] = '\0';


	printf("\nEnter month of payment\n");
	scanf("%s", month);
	strcpy(deleteExpense.month, month);
	deleteExpense.month[strlen(month)] = '\0';
	(deleteExpense.month)[strcspn(deleteExpense.month, "\n")] = '\0';
	
	printf("\nEnter year of payment\n");
	scanf("%s", year);
	strcpy(deleteExpense.year, year);
	deleteExpense.year[strlen(year)] = '\0';
	(deleteExpense.year)[strcspn(deleteExpense.year, "\n")] = '\0';
       
       
	printf("\n");
	write(socket_fd, &deleteExpense, sizeof(Expense));

	printf("Expense : %s payed on :%s-%s-%s is deleted successfully.\n", deleteExpense.type, deleteExpense.day, deleteExpense.month, deleteExpense.year);
	
}
