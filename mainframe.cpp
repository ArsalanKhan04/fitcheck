#include "mainframe.h"
#include <wx\notebook.h>
#include <wx\statline.h>


IndividualPage::IndividualPage(wxPanel* panel, wxSizer* sizer) {
	individualViewPanel = new wxPanel(panel, wxID_ANY);
	individualViewPanel->SetBackgroundColour(wxColour(230, 230, 230));
	individualViewSizer = new wxBoxSizer(wxVERTICAL);

	individualImage = new wxImage("preview.png", wxBITMAP_TYPE_PNG);
	individualImage->Rescale(270, 350);
	individualBitmapImage = new wxBitmap(*individualImage);
	individual_bitmap = new wxStaticBitmap(individualViewPanel, wxID_ANY, *individualBitmapImage);

	individualViewSizer->Add(individual_bitmap, wxSizerFlags().Center().DoubleBorder());
	individualProductTitle = new wxStaticText(individualViewPanel, wxID_ANY, wxT("Product Title Here"), wxDefaultPosition, wxSize(250, -1), wxALIGN_CENTER_HORIZONTAL);
	individualProductPrice = new wxStaticText(individualViewPanel, wxID_ANY, wxT("Product Price Here"), wxDefaultPosition, wxSize(250, -1), wxALIGN_CENTER_HORIZONTAL);
	individualProductBrand = new wxStaticText(individualViewPanel, wxID_ANY, wxT("Product Brand here"), wxDefaultPosition, wxSize(250, -1), wxALIGN_CENTER_HORIZONTAL);

	colorPanel = new wxPanel(individualViewPanel, wxID_ANY);
	colorView = new wxBoxSizer(wxHORIZONTAL);
	individualProductColor = new wxStaticText(colorPanel, wxID_ANY, wxT("Product Color"), wxDefaultPosition, wxSize(200, -1), wxALIGN_CENTER_HORIZONTAL);
	wxImage image(20, 20);
	image.SetRGB(wxRect(0, 0, 20, 20), 30, 30, 30);
	wxBitmap bitmap(image);
	individualProductColorImage = new wxStaticBitmap(colorPanel, wxID_ANY, bitmap);
	colorView->Add(individualProductColor, wxSizerFlags().DoubleBorder().Center());
	colorView->Add(individualProductColorImage, wxSizerFlags().DoubleBorder().Center());


	individualViewSizer->Add(individualProductTitle, wxSizerFlags().Center().DoubleBorder());
	individualViewSizer->Add(individualProductPrice, wxSizerFlags().Center().DoubleBorder());
	individualViewSizer->Add(individualProductBrand, wxSizerFlags().Center().DoubleBorder());
	individualViewSizer->Add(colorPanel, wxSizerFlags().Center().DoubleBorder());

	individualViewPanel->SetSizer(individualViewSizer);
	sizer->Add(individualViewPanel, wxSizerFlags().CenterVertical().DoubleBorder());

}

void IndividualPage::switchPage(const Item* item) {


	wxImage* newImage = new wxImage(item->getImageLinks()[0], wxBITMAP_TYPE_PNG);
	newImage->Rescale(270, 350);
	wxBitmap newBitmap(*newImage);
	individual_bitmap->SetBitmap(newBitmap);


	individualProductTitle->SetLabel(item->getProductTitle());
	individualProductPrice->SetLabel(item->getPrice());
	individualProductBrand->SetLabel(item->getBrand());
	individualProductColor->SetLabel(item->getColor());

	int hex = item->getColorHex();
	int red = (hex >> 16) & 0xFF;
	int green = (hex >> 8) & 0xFF;
	int blue = hex & 0xFF;
	wxImage image(20, 20);
	image.SetRGB(wxRect(0, 0, 20, 20), red, green, blue);
	wxBitmap bitmap(image);

	individualProductColorImage->SetBitmap(bitmap);
	


}


template <class T>
ItemPages::ItemPages(const std::vector<T*, std::allocator<T*>> &itemvec, wxPanel* panel, wxSizer* sizer) {
	// Adding Panel to keep all the items
	wxScrolledWindow* viewPanel = new wxScrolledWindow(panel, wxID_ANY, wxDefaultPosition, wxSize(-1, 800));
	wxGridSizer* viewSizer = new wxGridSizer(4, 10, 10);
	viewPanel->SetBackgroundColour(wxColour(200, 200, 200));

	//defining the panel for each item
	wxPanel* eachPanel;
	wxBoxSizer* eachSizer;
	wxImage* image;
	wxBitmap* bitmapImage;
	wxStaticBitmap* m_bitmap;
	wxStaticText* productTitle;
	wxPanel* buttonPanel;
	wxBoxSizer* buttonSizer;
	wxButton* viewButton;
	wxButton* addButton;

	for (const Item* eachitem : itemvec) {
		eachPanel = new wxPanel(viewPanel, wxID_ANY);
		eachSizer = new wxBoxSizer(wxVERTICAL);

		//Create a wxBitmap for image
		image = new wxImage(eachitem->getImageLinks()[0], wxBITMAP_TYPE_PNG);
		image->Rescale(100, 150);
		bitmapImage = new wxBitmap(*image);
		m_bitmap = new wxStaticBitmap(eachPanel, wxID_ANY, *bitmapImage);
		// Adding it to the individual part
		eachSizer->Add(m_bitmap, wxSizerFlags().Center().DoubleBorder());
		// Add the Product Name
		productTitle = new wxStaticText(eachPanel, wxID_ANY, wxT("" + eachitem->getProductTitle()), wxDefaultPosition, wxSize(150, -1), wxALIGN_CENTRE_HORIZONTAL);
		eachSizer->Add(productTitle, wxSizerFlags().Center().DoubleBorder());
		// add a button
		buttonPanel = new wxPanel(eachPanel, wxID_ANY);
		buttonSizer = new wxBoxSizer(wxHORIZONTAL);
		viewButton = new wxButton(buttonPanel, wxID_ANY, wxT("View"));
		viewButton->Bind(wxEVT_BUTTON, [this, eachitem] (wxCommandEvent& event) {
			rightPage->switchPage(eachitem);
			});
		addButton = new wxButton(buttonPanel, wxID_ANY, wxT("Add"));
		buttonSizer->Add(viewButton, wxSizerFlags().DoubleBorder());
		buttonSizer->Add(addButton, wxSizerFlags().DoubleBorder());
		buttonPanel->SetSizer(buttonSizer);

		eachSizer->Add(buttonPanel);

		eachPanel->SetBackgroundColour(wxColour(240, 240, 240));
		eachPanel->SetSizer(eachSizer);


		viewSizer->Add(eachPanel, wxSizerFlags().DoubleBorder());
	}
	
	viewPanel->SetScrollbars(0, 10, 0, 10);
	viewPanel->SetSizer(viewSizer);


	//adding the whole view to the wardrobe
	sizer->Add(viewPanel, wxSizerFlags().Expand().DoubleBorder());

	rightPage = new IndividualPage(panel, sizer);

}




MainFrame::MainFrame(const wxString& title, const User* user) :
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1200,700))
{

	alldata = new Data;
	alldata->load();

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
	ItemPages* rightitems = new ItemPages(alldata->getBottoms(), totalViewPanel, totalViewSizer);

	// ------------------------------------------------

	// ------------------------------------------------
	// Making Individual View here
	

	
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