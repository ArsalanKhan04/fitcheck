#include "mainframe.h"
#include <wx\notebook.h>
#include <wx\statline.h>


ItemPages::ItemPages(std::vector<Item*> &itemvec, wxPanel* panel, wxSizer* sizer) {
	// Adding Panel to keep all the items
	wxPanel* viewPanel = new wxPanel(panel, wxID_ANY);
	wxGridSizer* viewSizer = new wxGridSizer(8, 10, 10);


	//defining the panel for each item
	wxPanel* eachPanel;
	wxBoxSizer* eachSizer;
	wxImage* image;
	wxBitmap* bitmapImage;
	wxStaticBitmap* m_bitmap;
	wxStaticText* productTitle;


	for (const Item* eachitem : itemvec) {
		eachPanel = new wxPanel(viewPanel, wxID_ANY);
		eachSizer = new wxBoxSizer(wxVERTICAL);

		//Create a wxBitmap for image
		image = new wxImage(eachitem->getImageLink(), wxBITMAP_TYPE_PNG);
		image->Rescale(100, 150);
		bitmapImage = new wxBitmap(*image);
		m_bitmap = new wxStaticBitmap(eachPanel, wxID_ANY, *bitmapImage);
		// Adding it to the individual part
		eachSizer->Add(m_bitmap, wxSizerFlags().Center().DoubleBorder());
		// Add the Product Name
		productTitle = new wxStaticText(eachPanel, wxID_ANY, wxT("" + eachitem->getProductTitle()));
		eachSizer->Add(productTitle, wxSizerFlags().Center().DoubleBorder());

		eachPanel->SetBackgroundColour(wxColour(200, 200, 200));
		eachPanel->SetSizer(eachSizer);


		viewSizer->Add(eachPanel, wxSizerFlags().DoubleBorder());
	}
	
	viewPanel->SetSizer(viewSizer);


	//adding the whole view to the wardrobe
	sizer->Add(viewPanel, wxSizerFlags().Expand().DoubleBorder());
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

	wxStaticLine* division = new wxStaticLine(wardrobePanel, wxID_ANY);
	wardrobeSizer->Add(division);
	

	// totalViewPanel (consisiting of individual item and a specific one too)
	wxPanel* totalViewPanel = new wxPanel(wardrobePanel, wxID_ANY);
	wxBoxSizer* totalViewSizer = new wxBoxSizer(wxHORIZONTAL);

	// -------------------------------------------
	// Adding Panel to keep all the items
	wxPanel* viewPanel = new wxPanel(totalViewPanel, wxID_ANY);
	wxGridSizer* viewSizer = new wxGridSizer(5, 10, 10);


	//defining the panel for each item
	wxPanel* eachPanel;
	wxBoxSizer* eachSizer;
	wxImage* image;
	wxBitmap* bitmapImage;
	wxStaticBitmap* m_bitmap;
	wxStaticText* productTitle;


	eachPanel = new wxPanel(viewPanel, wxID_ANY);
	eachSizer = new wxBoxSizer(wxVERTICAL);

	//Create a wxBitmap for image
	image = new wxImage("camb_awbot_0000a.png", wxBITMAP_TYPE_PNG);
	image->Rescale(100, 150);
	bitmapImage = new wxBitmap(*image);
	m_bitmap = new wxStaticBitmap(eachPanel, wxID_ANY, *bitmapImage);
	// Adding it to the individual part
	eachSizer->Add(m_bitmap, wxSizerFlags().Center().DoubleBorder());
	// Add the Product Name
	productTitle = new wxStaticText(eachPanel, wxID_ANY, wxT("Product Title"));
	eachSizer->Add(productTitle, wxSizerFlags().Center().DoubleBorder());

	eachPanel->SetBackgroundColour(wxColour(200, 200, 200));
	eachPanel->SetSizer(eachSizer);
	viewSizer->Add(eachPanel, wxSizerFlags().DoubleBorder());
	viewPanel->SetSizer(viewSizer);

	// ------------------------------------------------

	// ------------------------------------------------
	// Making Individual View here
	wxPanel* individualViewPanel;
	wxBoxSizer* individualViewSizer;
	wxImage* individualImage;
	wxBitmap* individualBitmapImage;
	wxStaticBitmap* individual_bitmap;
	wxStaticText* individualProductTitle;

	individualViewPanel = new wxPanel(totalViewPanel, wxID_ANY);
	individualViewSizer = new wxBoxSizer(wxVERTICAL);

	individualImage = new wxImage("camb_awbot_0000a.png", wxBITMAP_TYPE_PNG);
	individualImage->Rescale(300, 400);
	individualBitmapImage = new wxBitmap(*individualImage);
	individual_bitmap = new wxStaticBitmap(individualViewPanel, wxID_ANY, *individualBitmapImage);

	individualViewSizer->Add(individual_bitmap, wxSizerFlags().Center().DoubleBorder());
	individualProductTitle = new wxStaticText(individualViewPanel, wxID_ANY, wxT("Product Title"));
	individualViewSizer->Add(individualProductTitle, wxSizerFlags().Center().TripleBorder());


	individualViewPanel->SetSizer(individualViewSizer);
	





	totalViewSizer->Add(viewPanel, wxSizerFlags().CenterVertical().DoubleBorder());
	totalViewSizer->Add(individualViewPanel, wxSizerFlags().CenterVertical().DoubleBorder());
	totalViewPanel->SetSizer(totalViewSizer);


	//adding the whole view to the wardrobe
	wardrobeSizer->Add(totalViewPanel, wxSizerFlags().Expand().DoubleBorder());



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