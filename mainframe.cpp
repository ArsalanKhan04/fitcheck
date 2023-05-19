#include "mainframe.h"

MainFrame::MainFrame(const wxString& title) :
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(800,600))
{
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	wxButton* button = new wxButton(panel, wxID_ANY);
}