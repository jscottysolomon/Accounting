#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

class databaseConnection {
public: 

	databaseConnection();// opens a connection to the database
	~databaseConnection(); // destructor

	boolean close(); // closes the connection to the database
	boolean isOpen() const; // returns true if the connection is open, false otherwise

private:
	MYSQL* conn; // pointer to a MySQL connection object
	bool opened;
};

#endif

