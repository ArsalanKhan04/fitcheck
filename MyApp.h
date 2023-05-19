#pragma once
#include <wx/wx.h>
#include "User.h"

class MyApp: public wxApp
{
private:
	User* CurrentUser;
public:
	// Called on application startup
	virtual bool OnInit();
	bool SetUser(std::string username, std::string password, std::string name, std::string email);
	int CheckIfValidUser(std::string username, std::string password);
	bool NewUser(std::string username, std::string password, std::string name, std::string email);
};

