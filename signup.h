#pragma once
#include <wx\wx.h>
#include "MyApp.h"

class FormEach {
private:
	wxString data;
	wxTextCtrl* placeholder;
	wxStaticText* arbitraryText;
	wxString message;
	bool validity;

	void enterData(wxCommandEvent&);

public:
	FormEach(wxPanel*, wxSizer*, const wxString &title, bool password);
	wxString getData() const;
	void setMessage(const wxString& text);
	void setValidity(bool);
	bool getValidity() const;
	virtual void validate() = 0;
};


class UsernameForm : public FormEach {
public:
	UsernameForm(wxPanel*, wxSizer*, const wxString& title, bool password);
	void validate() override;
};
class PasswordForm : public FormEach {
public:
	PasswordForm(wxPanel*, wxSizer*, const wxString& title, bool password);
	void validate() override;
};
class EmailForm : public FormEach {
public:
	EmailForm(wxPanel*, wxSizer*, const wxString& title, bool password);
	void validate() override;
};
class NameForm : public FormEach {
public:
	NameForm(wxPanel*, wxSizer*, const wxString& title, bool password);
	void validate() override;
};




class SignupFrame : public wxFrame
{
private:
	void login(wxCommandEvent&);
	void signup(wxCommandEvent&);
	void checkIfSignupValid(wxCommandEvent&);
	void checkIfLoginValid(wxCommandEvent&);

	wxStaticText* errorMessageSignup;
	wxStaticText* errorMessageLogin;
	FormEach* nameSignup;
	FormEach* usernameSignup;
	FormEach* passwordSignup;
	FormEach* confirmPasswordSignup;
	FormEach* emailSignup;
	FormEach* usernameLogin;
	FormEach* passwordLogin;
	wxButton* signupButton;
	wxButton* loginButton;

public:
	SignupFrame(const wxString& title);

	void SetUser(int userId);
	int CheckIfUser(const std::string& username);
	int CheckIfValidUser(const std::string& username, const std::string& password);
	void NewUser(const std::string& username, const std::string& password, const std::string& name, const std::string& email);

};

