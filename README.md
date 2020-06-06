# accounting_system
Accounting system for 6th semestar course called System Programming, developed in C using Linux
TCP Server - Client implementation
# Installation
Step 1

Run database_query.sql
Change the password in server/database/database_connection.c to your localhost password, in order to establish the connection.
Step 2

Open your terminal in the same folder and run the following commands:

gcc -o resultServer server/server.c -lmysqlclient

gcc -o resultClient client/client.c -lmysqlclient

# Run

Run the following commands to start the program:

./resultServer

./resultClient
