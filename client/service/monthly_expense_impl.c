void printMonthlyExpense(int socket_fd) {
//Expense monthlyExpense;
double total;
read(socket_fd, &total, sizeof(Expense*));

printf("Total expense : %.2lf\n", total);

printf("\n");
}
