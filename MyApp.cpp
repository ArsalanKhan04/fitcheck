#include "MyApp.h"
#include "signup.h"
#include "mainframe.h"

wxLogWindow* debugger;

bool MyApp::OnInit()
{
	// Initialising the image handler
	wxImage::AddHandler(new wxPNGHandler);
	debugger = new wxLogWindow(NULL, "log window");
	// Set the log target to the log window
	wxLog::SetActiveTarget(debugger);

	// Create the main application window
	SignupFrame* frame = new SignupFrame(wxT("Sign Up"));

	
	frame->Show(true);

	// start the event loop
	return true;
	
}


IMPLEMENT_APP(MyApp)

