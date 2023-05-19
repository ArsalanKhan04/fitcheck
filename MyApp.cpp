#include "MyApp.h"
#include "signup.h"
#include "mainframe.h"

User* CurrentUser = new User;

bool MyApp::OnInit()
{

	MainFrame* mainframe = new MainFrame(wxT("FITcheck"));

	// Create the main application window
	SignupFrame* frame = new SignupFrame(wxT("Sign Up"));


	// Show it
	mainframe->Show(true);
	frame->Show(true);

	// start the event loop
	return true;
	
}


IMPLEMENT_APP(MyApp)