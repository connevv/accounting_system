//add_expense_impl.c
Expense initializeExpense();
void addNewExpense(int socket_fd);

//delete_expense_impl.c
void deleteExpense(int socket_fd);


//print_expenses.c
void printAllExpenses(int socket_fd);

//biggest_expense_impl.c
void printBiggestExpense(int socket_fd);

//monthly_expense_impl.c
void printMonthlyExpense(int socket_fd);

//client_tcp_impl.c
void printMenu();
int createSocket();
void connectToServer(int socket_fd);
void serverComunicationService(int socket_fd);
