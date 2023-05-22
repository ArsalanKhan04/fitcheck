#pragma once
#include <iostream>
#include <regex>

class User
{
private:
	int id;
	bool loggedin;
	std::string username;
	std::string password;
	std::string name;
	std::string email;
	bool isValidUsername(const std::string& username);
	bool isValidPassword(const std::string& password);
	bool isValidName(const std::string& name);
	bool isValidEmail(const std::string& email);
public:
	int getid() const;
	std::string getusername() const;
	std::string getpassword() const;
	std::string getname() const;
	std::string getemail() const;
	void setusername(const std::string&);
	void setpassword(const std::string&);
	void setname(const std::string&);
	void setemail(const std::string&);
	User();
	void init(int id, const std::string& username, const std::string& password, const std::string& name, const std::string& email);

};

