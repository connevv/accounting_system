#include <mysql/mysql.h>
#include <string.h>
#include <stdio.h>
void loadExpensesFromDatabase(){
	MYSQL_RES *result;
	MYSQL_ROW row;
	const char s[2] = "-";
	char *selectAllQuery = "SELECT * FROM accounting_db.Expenses";
	
	if((mysql_query(mysql_connection, selectAllQuery))) {
		printf("%s\n", mysql_error(mysql_connection));
	}
	
	result = mysql_use_result(mysql_connection);
	
	while ((row = mysql_fetch_row(result))) {
		
		ExpenseList* newNode = (ExpenseList*)malloc(sizeof(ExpenseList));
		

		strcpy(newNode->expense.type, row[1]);
		newNode->expense.type[strlen(row[1])]='\0';
		
		newNode->expense.cost = atof(row[2]);
		
		char date[15];
		strcpy(date, row[3]);

		
		char *year = strtok(date, s);
		strcpy(newNode->expense.year, year);
		newNode->expense.day[strlen(year)]='\0';
		
		char *month = strtok(NULL, s);
		strcpy(newNode->expense.month, month);
		newNode->expense.day[strlen(month)]='\0';
		
		char *day = strtok(NULL, s);
		strcpy(newNode->expense.day, day);
		newNode->expense.day[strlen(day)]='\0';

		/*printf("Expense : %s\n Cost: %f\n Date: %s-%s-%s\n", newNode->expense.type, newNode->expense.cost, 
		newNode->expense.day, newNode->expense.month, newNode->expense.year); */
		newNode->next = head;
		head = newNode;
	}
	mysql_free_result(result);
}
