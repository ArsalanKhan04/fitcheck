#include "signup.h"
#include "MyApp.h"
#include <wx\position.h>
#include <wx\notebook.h>
#include <regex>

// Each Form Element with a function to get individual data
FormEach :: FormEach(wxPanel* parentPanel, wxSizer* parentSizer, const wxString &title, bool password) {
	// font for username and password label
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
	return data;
}
void FormEach::enterData(wxCommandEvent&){
	this->data = placeholder->GetValue();
	validate();
	arbitraryText->Refresh();
	arbitraryText->SetLabel(message); // Can and will be used to display additional text
	wxColour myColor = validity ? *wxGREEN : *wxRED;
	arbitraryText->SetForegroundColour(myColor);
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


void SignupFrame::login(wxCommandEvent&) {

}
void SignupFrame::signup(wxCommandEvent&) {

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
	wxPanel* loginPanel = new wxPanel(notebook, wxID_ANY);
	notebook->AddPage(signupPanel, wxT("Sign Up"), true);
	notebook->AddPage(loginPanel, wxT("Log In"), false);


	// Setting a staticBox for Signup and Login
	wxBoxSizer* signupSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* loginSizer = new wxBoxSizer(wxVERTICAL);

	// signup Panel
	nameSignup = new NameForm(signupPanel, signupSizer, "Full Name", false);
	usernameSignup = new UsernameForm(signupPanel, signupSizer, "Username", false);
	passwordSignup = new PasswordForm(signupPanel, signupSizer, "New Password", true);
	confirmPasswordSignup = new PasswordForm(signupPanel, signupSizer, "Confirm Password", true);
	emailSignup = new EmailForm(signupPanel, signupSizer, "Email", false);
	wxButton* signupButton = new wxButton(signupPanel, wxID_ANY, wxT("Sign Up!"), wxPoint(230, 200), wxSize(120, 30));
	signupSizer->Add(signupButton, wxSizerFlags().Center().DoubleBorder());

	// Username for login Panel

	loginSizer->Add(10, 40);
	usernameLogin = new UsernameForm(loginPanel, loginSizer, "Username", false);
	passwordLogin = new PasswordForm(loginPanel, loginSizer, "Password", true);
	wxButton* loginButton = new wxButton(loginPanel, wxID_ANY, wxT("Log in!"), wxPoint(230, 200), wxSize(120, 30));
	loginSizer->Add(loginButton, wxSizerFlags().Center().DoubleBorder());





	signupPanel->SetSizer(signupSizer);
	loginPanel->SetSizer(loginSizer);

	topSizer->Add(notebook, wxSizerFlags().Center().CenterVertical().DoubleBorder());
}