#include "MyApp.h"
#include "signup.h"
#include "mainframe.h"


bool MyApp::OnInit()
{
	// Initialising the image handler
	wxImage::AddHandler(new wxPNGHandler);



	// Create the main application window
	SignupFrame* frame = new SignupFrame(wxT("Sign Up"));

	
	frame->Show(true);

	// start the event loop
	return true;
	
}


IMPLEMENT_APP(MyApp)

