#include "MyApp.h"
#include "signup.h"
#include <sqlite3.h>

bool MyApp::OnInit()
{

	
	// Create the main application window
	SignupFrame* frame = new SignupFrame(wxT("Sign Up"));

	// Show it
	frame->Show(true);

	// start the event loop
	return true;

}

bool MyApp::SetUser(std::string username, std::string password, std::string name, std::string email) {
	CurrentUser = new User(username, password, name, email);
	return true;
}

int CheckIfValidUser(std::string username, std::string password) {
    sqlite3* db;
    int rc = sqlite3_open("fitcheck.db", &db);
    
    if (rc)
    {
        throw std::runtime_error("Cannot open database: " + std::string(sqlite3_errmsg(db)));
    }

    std::string sql = "SELECT id FROM users WHERE username = ? AND password = ?";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        throw std::runtime_error("Cannot prepare statement: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

    int userId = -1;
    rc = sqlite3_exec(db, "BEGIN TRANSACTION", nullptr, nullptr, nullptr);

    if (rc != SQLITE_OK)
    {
        throw std::runtime_error("Cannot begin transaction: " + std::string(sqlite3_errmsg(db)));
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        // Retrieve the user ID
        userId = sqlite3_column_int(stmt, 0);
    }

    rc = sqlite3_exec(db, "END TRANSACTION", nullptr, nullptr, nullptr);

    if (rc != SQLITE_OK)
    {
        throw std::runtime_error("Cannot end transaction: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return userId;
}

IMPLEMENT_APP(MyApp)