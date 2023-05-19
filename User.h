#pragma once
#include <iostream>
#include <regex>

class User
{
private:
	std::string username;
	std::string password;
	std::string name;
	std::string email;
	bool isValidUsername(const std::string& username);
	bool isValidPassword(const std::string& password);
	bool isValidName(const std::string& name);
	bool isValidEmail(const std::string& email);
public:
	std::string getusername();
	std::string getpassword();
	std::string getname();
	std::string getemail();
	void setusername(std::string);
	void setpassword(std::string);
	void setname(std::string);
	void setemail(std::string);
	User(std::string username, std::string password, std::string name, std::string email);

};

