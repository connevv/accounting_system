void connectToDatabase(){
	char* SERVER = "localhost";
	char* USER = "root";
	char* PASSWORD = "jovan123";
	char* DATABASE = "accounting_db";
	mysql_connection=mysql_init(NULL);
	if (!(mysql_real_connect(mysql_connection, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0))) {
		printf("here ->%s\n", mysql_error(mysql_connection));
	}
}
