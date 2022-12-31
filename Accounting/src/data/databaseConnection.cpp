#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <mysql.h>

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/fileconf.h>

#include "databaseConnection.h"

databaseConnection::databaseConnection() {
	wxFileConfig config("config.properties");

	//Retrieve information from config.properties
	wxString host = config.Read("database.host");
	wxString user = config.Read("database.user");
	wxString password = config.Read("database.password");
	wxString dbname = config.Read("database.dbname");

	std::string host_str = host.ToStdString();
	std::string user_str = user.ToStdString();
	std::string password_str = password.ToStdString();
	std::string dbname_str = dbname.ToStdString();

	conn = mysql_init(0);

	if (!mysql_real_connect(conn, host_str.c_str(), user_str.c_str(), password_str.c_str(), dbname_str.c_str(), 0, NULL, 0)) {
		// Error handling
		wxMessageBox("Failed to connect to the database!");
	}
}

boolean databaseConnection::isOpen() const
{
	try {
		mysql_close(conn);
	}
	catch (const std::exception& e) {
		return false;
	}

	return true;
}

boolean databaseConnection::close() {
	mysql_close(conn);
	
}

databaseConnection::~databaseConnection() {
	mysql_close(conn);
}