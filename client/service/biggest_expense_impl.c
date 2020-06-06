void printBiggestExpense(int socket_fd) {
Expense biggestExpense;

read(socket_fd, &biggestExpense, sizeof(Expense));

printf("Biggest expense:\n");
printf("Type: %s cost %.2lf payed on: %s-%s-%s", biggestExpense.type, biggestExpense.cost, biggestExpense.day, biggestExpense.month, biggestExpense.year);
printf("\n");
}
