#include "User.h"

User::User() {
    this->id = -1;
    this->username = "";
    this->password = "";
    this->name = "";
    this->email = "";

    this->loggedin = false;

	
}

void User::init(int id, const std::string& username, const std::string& password, const std::string& name, const std::string& email)
{

    if (!isValidUsername(username)) {
        throw std::invalid_argument("Invalid username. Please provide a valid username.");
    }

    if (!isValidPassword(password)) {
        throw std::invalid_argument("Invalid password. Please provide a valid password.");
    }

    if (!isValidName(name)) {
        throw std::invalid_argument("Invalid name. Please provide a valid name.");
    }

    if (!isValidEmail(email)) {
        throw std::invalid_argument("Invalid email. Please provide a valid email address.");
    }
    this->id = id;
    this->username = username;
    this->password = password;
    this->name = name;
    this->email = email;
    this->loggedin = true;



}
int User::getid() {
    return id;
}
std::string User::getname() {
	return name;
}

std::string User::getemail() {
	return email;
}

std::string User::getpassword() {
	return password;
}

std::string User::getusername() {
	return username;
}

void User::setusername(const std::string& username) {
    if (!isValidUsername(username)) {
        throw std::invalid_argument("Invalid username. Please provide a valid username.");
    }
	this->username = username;
}

void User::setpassword(const std::string& password) {
    if (!isValidPassword(password)) {
        throw std::invalid_argument("Invalid password. Please provide a valid password.");
    }
	this->password = password;
}

void User::setname(const std::string& name) {
    if (!isValidName(name)) {
        throw std::invalid_argument("Invalid name. Please provide a valid name.");
    }
	this->name = name;
}

void User::setemail(const std::string& email) {
    if (!isValidEmail(email)) {
        throw std::invalid_argument("Invalid email. Please provide a valid email address.");
    }
	this->email = email;
}

bool User::isValidUsername(const std::string& username) {
    return (username.length() >= 8 && username.length() <= 30);
}

bool User::isValidPassword(const std::string& password) {
    return (password.length() >= 8) && password.length() <=30;
}

bool User::isValidName(const std::string& name) {
    return (!name.empty());
}

bool User::isValidEmail(const std::string& email) {
    std::regex emailRegex(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})");
    return std::regex_match(email, emailRegex);
}



