#include "mainframe.h"
#include <wx\notebook.h>


ItemPages::ItemPages(std::vector<Item>&) {

}


MainFrame::MainFrame(const wxString& title, const User* user) :
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1200,700))
{

	// Adding the icon to the frame and the window
	wxIcon icon;
	icon.LoadFile("ficon.ico", wxBITMAP_TYPE_ICO);
	this->SetIcon(icon);
	wxTopLevelWindow::SetIcon(icon);

	// Creating the sizer to include the main panel
	wxBoxSizer* topsizer = new wxBoxSizer(wxVERTICAL);
	

	// Creating the main panel to include everything
	wxPanel* mainpanel = new wxPanel(this, wxID_ANY);

	// Creating a sizer for the mainpanel
	wxBoxSizer* mainPanelSizer = new wxBoxSizer(wxVERTICAL);

	// Creating individual panels for wardrobe and all clothes, adding them to the notebook
	wxImageList* notebookimages = new wxImageList(32, 32, true, 1);
	
	wxIcon cartIcon;
	cartIcon.LoadFile(wxT("cart.ico"), wxBITMAP_TYPE_ICO);
	wxIcon closetIcon;
	closetIcon.LoadFile(wxT("closet.ico"), wxBITMAP_TYPE_ICO);
	wxBitmap notebookImage1(closetIcon);
	wxBitmap notebookImage2(cartIcon);
	int panel1img = notebookimages->Add(notebookImage1);
	int panel2img = notebookimages->Add(notebookImage2);

	// Adding pages with their icons
	wxNotebook* mainNotebook = new wxNotebook(mainpanel, wxID_ANY);
	mainNotebook->AssignImageList(notebookimages);
	wxPanel* wardrobePanel = new wxPanel(mainNotebook, wxID_ANY);
	wxPanel* allClothesPanel = new wxPanel(mainNotebook, wxID_ANY);
	mainNotebook->AddPage(wardrobePanel, wxT("Your Wardrobe"), true, panel1img);
	mainNotebook->AddPage(allClothesPanel, wxT("Get More Clothes"), false, panel2img);
	
	
	// Creating sizers for wardrobe and all clothes pages
	wxBoxSizer* wardrobeSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* allClothesSizer = new wxBoxSizer(wxVERTICAL);



	// Adding Label for both
	wxFont* labelFont = new wxFont(15, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxStaticText* wardrobeLabel = new wxStaticText(wardrobePanel, wxID_ANY, wxT("Your Wardrobe"));
	wxStaticText* allClothesLabel = new wxStaticText(allClothesPanel, wxID_ANY, wxT("All Clothes"));
	wardrobeLabel->SetFont(*labelFont);
	allClothesLabel->SetFont(*labelFont);
	wardrobeSizer->Add(wardrobeLabel, wxSizerFlags().Left().DoubleBorder());
	allClothesSizer->Add(allClothesLabel, wxSizerFlags().Left().DoubleBorder());


	// Adding Panel to keep all the images
	wxPanel* viewPanel = new wxPanel(wardrobePanel, wxID_ANY);
	wxGridSizer* viewSizer = new wxGridSizer(3, 10, 10);


	viewPanel->SetSizer(viewSizer);

	// Assigning sizers for each panel of the notebook
	wardrobePanel->SetSizer(wardrobeSizer);
	allClothesPanel->SetSizer(allClothesSizer);


	// Assigning sizer for main panel
	mainPanelSizer->Add(mainNotebook, wxSizerFlags().Expand());
	mainpanel->SetSizer(mainPanelSizer);

	// Assigning sizer for main window
	topsizer->Add(mainpanel, wxSizerFlags().Expand());
	SetSizer(topsizer);
	
}