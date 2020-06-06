//database
//database_conection.c
void connectToDatabase();
//load_expenses.c
void loadExpensesFromDatabase();

//services

//add_expense.c
void addExpenseToDb(Expense expense);
int compareExpenses(Expense expense1, Expense expense2);
void addExpenseToList(Expense newExpense);
void addNewExpense(int client_connection_fd);

//delete_expense.c
void deleteExpenseFromDb(Expense expenseToRemove);
int compareExpenses(Expense expense1, Expense expense2);
void deleteExpenseFromList(Expense expenseToRemove);
void deleteExpense(int client_connection_fd);

//print_expenses.c
void printExpenses(int client_connection_fd);

//biggest_expense.c
void getBiggestExpense (int client_connection_fd);

//monthly_expense.c
void getMonthlyExpense (int client_connection_fd);

//comunication
//server_tcp_socket_implementation.c
int connectToClient(int socket_fd);
void makeServerListen(int socket_fd);
struct sockaddr_in initializeServer();
void bindServerToLocalHost(int socket_fd, struct sockaddr_in serverAddress);
int createSocket();
void clientComunicationService(int client_connection_fd);
