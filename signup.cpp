#include "signup.h"
#include "MyApp.h"
#include "User.h"
#include <sqlite3.h>
#include <wx\position.h>
#include <wx\notebook.h>
#include <wx\string.h>
#include <regex>

// Each Form Element with a function to get individual data
FormEach :: FormEach(wxPanel* parentPanel, wxSizer* parentSizer, const wxString &title, bool password) {
	// font for username and password label
    validity = false;
    wxFont myFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM);

	wxBoxSizer* eachSizer = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* label = new wxStaticText(parentPanel, wxID_ANY, title + wxT(": "), wxPoint(150, 100), wxSize(150, -1), wxALIGN_LEFT);
	label->SetFont(myFont);

	long textStyle = password ? wxTE_PASSWORD : 0;

	placeholder = new wxTextCtrl(parentPanel, wxID_ANY, wxEmptyString, wxPoint(300, 100), wxSize(200, -1), textStyle);
	placeholder->Bind(wxEVT_TEXT, &FormEach::enterData, this);
	arbitraryText = new wxStaticText(parentPanel, wxID_ANY, wxT(""), wxPoint(350, 100), wxSize(200, -1));
	
	eachSizer->Add(label);
	eachSizer->Add(placeholder);
	eachSizer->Add(arbitraryText, wxSizerFlags().DoubleBorder(wxLEFT));

	parentSizer->Add(eachSizer, wxSizerFlags().Center().DoubleBorder());
}
wxString FormEach::getData() const{
    return placeholder->GetValue();
}
void FormEach::enterData(wxCommandEvent& evt){
	this->data = placeholder->GetValue();
	validate();
	arbitraryText->Refresh();
	arbitraryText->SetLabel(message); // Can and will be used to display additional text
	wxColour myColor = validity ? *wxGREEN : *wxRED;
	arbitraryText->SetForegroundColour(myColor);
    evt.Skip();
}
void FormEach::setMessage(const wxString& text) {
	message = text;
}
void FormEach::setValidity(bool valid) {
	validity = valid;
}
bool FormEach::getValidity() const {
	return validity;
}

UsernameForm::UsernameForm(wxPanel* panel, wxSizer* sizer, const wxString& title, bool password)
	: FormEach(panel, sizer, title, password) {
}
void UsernameForm::validate() {
	if (getData().Length() <= 8) {
		setMessage("Username too small");
		setValidity(false);
	}
	else if (getData().Length() >= 30) {
		setMessage("Username too Large");
		setValidity(false);
	}
	else {
		setMessage("Valid Username!");
		setValidity(true);
	}
}

PasswordForm::PasswordForm(wxPanel* panel, wxSizer* sizer, const wxString& title, bool password)
	: FormEach(panel, sizer, title, password) {
}
void PasswordForm::validate() {
	if (getData().Length() <= 8) {
		setMessage("Password too small");
		setValidity(false);
	}
	else if (getData().Length() >= 30) {
		setMessage("Password too Large");
		setValidity(false);
	}
	else {
		setMessage("Valid Password!");
		setValidity(true);
	}
}

EmailForm::EmailForm(wxPanel* panel, wxSizer* sizer, const wxString& title, bool password)
	: FormEach(panel, sizer, title, password) {
}
void EmailForm::validate() {
	std::regex emailRegex(R"([A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,})");
	if (!std::regex_match(getData().ToStdString(), emailRegex)) {
		setMessage("Invalid Email!");
		setValidity(false);
	}
	else
	{
		setMessage("Valid Email!");
		setValidity(true);
	}
}

NameForm::NameForm(wxPanel* panel, wxSizer* sizer, const wxString& title, bool password)
	: FormEach(panel, sizer, title, password) {
}
void NameForm::validate() {
	if (getData().empty()) {
		setMessage("Please Enter a name");
		setValidity(false);
	}
	else {
		setMessage(":)");
		setValidity(true);
	}
}

void SignupFrame::checkIfLoginValid(wxCommandEvent&) {
    if (usernameLogin->getValidity() && passwordLogin->getValidity()) {
        loginButton->Bind(wxEVT_BUTTON, &SignupFrame::login, this);
        loginButton->SetForegroundColour(*wxGREEN);
    }
    else {
        loginButton->Unbind(wxEVT_BUTTON, &SignupFrame::login, this);
        loginButton->SetForegroundColour(*wxRED);
    }
}
void SignupFrame::checkIfSignupValid(wxCommandEvent&) {
    if (usernameSignup->getValidity() && passwordSignup->getValidity() && emailSignup->getValidity() && nameSignup->getValidity() && confirmPasswordSignup->getValidity()) {
        signupButton->Bind(wxEVT_BUTTON, &SignupFrame::signup, this);
        loginButton->SetForegroundColour(*wxGREEN);
    }
    else {
        signupButton->Unbind(wxEVT_BUTTON, &SignupFrame::signup, this);
        loginButton->SetForegroundColour(*wxRED);
    }
}

void SignupFrame::login(wxCommandEvent&) {
    wxString username = usernameLogin->getData();
    wxString password =  passwordLogin->getData();
    int userId = CheckIfValidUser(username.ToStdString(), password.ToStdString());
    if (CheckIfUser(username.ToStdString()) == -1) {
        errorMessageLogin->SetLabel(wxT("The following user was not found"));
        return;
    }
    if (userId == -1) {
        errorMessageLogin->SetLabel(wxT("Your Password is Invalid!"));
        return;
    }
    try {
        SetUser(userId);
    }
    catch (std::exception ex) {
        errorMessageLogin->SetLabel(ex.what());
    }
    errorMessageLogin->SetLabel(CurrentUser->getusername());
}
void SignupFrame::signup(wxCommandEvent&) {
    wxString username = usernameSignup->getData();
    wxString password = passwordSignup->getData();
    wxString passwordConfirm = confirmPasswordSignup->getData();
    wxString email = emailSignup->getData();
    wxString name = nameSignup->getData();
    if (CheckIfUser(username.ToStdString()) != -1) {
        errorMessageSignup->SetLabel(wxT("This user already exists!"));
        return;
    }
    if (!password.IsSameAs(passwordConfirm)) {
        errorMessageSignup->SetLabel(wxT("The Password Re entered is false!"));
    }
    try {
        NewUser(username.ToStdString(), password.ToStdString(), email.ToStdString(), name.ToStdString());
        int userId = CheckIfValidUser(username.ToStdString(), password.ToStdString());
        SetUser(userId);
    }
    catch (std::exception ex) {
        errorMessageSignup->SetLabel(ex.what());
        errorMessageSignup->SetLabel(wxT("Invalid!"));
        return;
    }
    errorMessageSignup->SetLabel(CurrentUser->getusername());
}


SignupFrame::SignupFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600,500))
{

	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(topSizer);
	
	// Signup And Login Notebook
	wxNotebook* notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition);


	// font for username and password label
	wxFont myFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM);


	// Setting a panel for Signup and login
	wxPanel* signupPanel = new wxPanel(notebook, wxID_ANY);
    signupPanel->Bind(wxEVT_TEXT, &SignupFrame::checkIfSignupValid, this);
	wxPanel* loginPanel = new wxPanel(notebook, wxID_ANY);
    loginPanel->Bind(wxEVT_TEXT, &SignupFrame::checkIfLoginValid, this);
	notebook->AddPage(signupPanel, wxT("Sign Up"), true);
	notebook->AddPage(loginPanel, wxT("Log In"), false);


	// Setting a staticBox for Signup and Login
	wxBoxSizer* signupSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* loginSizer = new wxBoxSizer(wxVERTICAL);

	// signup Panel
	errorMessageSignup = new wxStaticText(signupPanel, wxID_ANY, wxT(""));
    errorMessageSignup->SetForegroundColour(*wxRED);
	signupSizer->Add(errorMessageSignup);
	nameSignup = new NameForm(signupPanel, signupSizer, "Full Name", false);
	usernameSignup = new UsernameForm(signupPanel, signupSizer, "Username", false);
	passwordSignup = new PasswordForm(signupPanel, signupSizer, "New Password", true);
	confirmPasswordSignup = new PasswordForm(signupPanel, signupSizer, "Confirm Password", true);
	emailSignup = new EmailForm(signupPanel, signupSizer, "Email", false);
	signupButton = new wxButton(signupPanel, wxID_ANY, wxT("Sign Up!"), wxPoint(230, 200), wxSize(120, 30));
	signupSizer->Add(signupButton, wxSizerFlags().Center().DoubleBorder());

	// Username for login Panel

	loginSizer->Add(10, 40);
	errorMessageLogin = new wxStaticText(loginPanel, wxID_ANY, wxT(""));
    errorMessageLogin->SetForegroundColour(*wxRED);
	loginSizer->Add(errorMessageLogin);
	usernameLogin = new UsernameForm(loginPanel, loginSizer, "Username", false);
	passwordLogin = new PasswordForm(loginPanel, loginSizer, "Password", true);
	loginButton = new wxButton(loginPanel, wxID_ANY, wxT("Log in!"), wxPoint(230, 200), wxSize(120, 30));
	loginSizer->Add(loginButton, wxSizerFlags().Center().DoubleBorder());





	signupPanel->SetSizer(signupSizer);
	loginPanel->SetSizer(loginSizer);

	topSizer->Add(notebook, wxSizerFlags().Center().CenterVertical().DoubleBorder());
}


void SignupFrame::SetUser(int userId) {
    sqlite3* db;
    int rc = sqlite3_open("fitcheck.db", &db);

    if (rc != SQLITE_OK)
    {
        throw std::runtime_error("Cannot open database: " + std::string(sqlite3_errmsg(db)));
    }

    std::string sql = "SELECT username, password, name, email FROM users WHERE _id = ?";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        throw std::runtime_error("Cannot prepare statement: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_int(stmt, 1, userId);

    rc = sqlite3_step(stmt);

    if (rc != SQLITE_ROW)
    {
        throw std::runtime_error("User not found with ID: " + std::to_string(userId));
    }

    std::string username(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    std::string password(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
    std::string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
    std::string email(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    CurrentUser->init(userId, username, password, name, email);
}

int SignupFrame::CheckIfUser(const std::string& username) {
    sqlite3* db;
    int rc = sqlite3_open("fitcheck.db", &db);

    if (rc)
    {
        throw std::runtime_error("Cannot open database: " + std::string(sqlite3_errmsg(db)));
    }

    std::string sql = "SELECT _id FROM users WHERE username = ?";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        throw std::runtime_error("Cannot prepare statement: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);

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

int SignupFrame::CheckIfValidUser(const std::string& username, const std::string& password) {
    sqlite3* db;
    int rc = sqlite3_open("fitcheck.db", &db);

    if (rc)
    {
        throw std::runtime_error("Cannot open database: " + std::string(sqlite3_errmsg(db)));
    }

    std::string sql = "SELECT _id FROM users WHERE username = ? AND password = ?";
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

void SignupFrame::NewUser(const std::string& username, const std::string& password, const std::string& email, const std::string& name)
{
    sqlite3* db;
    int rc = sqlite3_open("fitcheck.db", &db);

    if (rc != SQLITE_OK)
    {
        throw std::runtime_error("Cannot open database: " + std::string(sqlite3_errmsg(db)));
    }

    std::string sql = "INSERT INTO users (username, password, email, name) VALUES (?, ?, ?, ?)";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK)
    {
        throw std::runtime_error("Cannot prepare statement: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, name.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);

    if (rc != SQLITE_DONE)
    {   
        throw std::runtime_error("Error inserting user: " + std::string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
