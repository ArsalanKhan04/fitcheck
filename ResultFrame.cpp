#include "ResultFrame.h"

ItemDisplay::ItemDisplay(Item* item, wxPanel* panel, wxSizer* sizer) {
	wxPanel* individualViewPanel = new wxPanel(panel, wxID_ANY);
	individualViewPanel->SetBackgroundColour(wxColour(230, 230, 230));
	wxBoxSizer* individualViewSizer = new wxBoxSizer(wxVERTICAL);

	wxImage* individualImage = new wxImage(item->getImageLinks()[0], wxBITMAP_TYPE_PNG);
	individualImage->Rescale(100, 150);
	wxBitmap* individualBitmapImage = new wxBitmap(*individualImage);
	wxStaticBitmap* individual_bitmap = new wxStaticBitmap(individualViewPanel, wxID_ANY, *individualBitmapImage);

	individualViewSizer->Add(individual_bitmap, wxSizerFlags().Center().DoubleBorder());
	wxStaticText* individualProductTitle = new wxStaticText(individualViewPanel, wxID_ANY, item->getProductTitle(), wxDefaultPosition, wxSize(150, -1), wxALIGN_CENTER_HORIZONTAL);
	wxStaticText* individualProductPrice = new wxStaticText(individualViewPanel, wxID_ANY, item->getPrice(), wxDefaultPosition, wxSize(150, -1), wxALIGN_CENTER_HORIZONTAL);
	wxStaticText* individualProductBrand = new wxStaticText(individualViewPanel, wxID_ANY, item->getBrand(), wxDefaultPosition, wxSize(150, -1), wxALIGN_CENTER_HORIZONTAL);

	wxPanel* colorPanel = new wxPanel(individualViewPanel, wxID_ANY);
	wxBoxSizer* colorView = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* individualProductColor = new wxStaticText(colorPanel, wxID_ANY, item->getColor(), wxDefaultPosition, wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL);
	
	int hex = item->getColorHex();
	int red = (hex >> 16) & 0xFF;
	int green = (hex >> 8) & 0xFF;
	int blue = hex & 0xFF;


	wxImage image(20, 20);

	image.SetRGB(wxRect(0, 0, 20, 20), red, green, blue);


	wxBitmap bitmap(image);
	wxStaticBitmap* individualProductColorImage = new wxStaticBitmap(colorPanel, wxID_ANY, bitmap);
	colorView->Add(individualProductColor, wxSizerFlags().DoubleBorder().Center());
	colorView->Add(individualProductColorImage, wxSizerFlags().DoubleBorder().Center());
	colorPanel->SetSizer(colorView);

	individualViewSizer->Add(individualProductTitle, wxSizerFlags().Center());
	individualViewSizer->Add(individualProductPrice, wxSizerFlags().Center());
	individualViewSizer->Add(individualProductBrand, wxSizerFlags().Center());
	individualViewSizer->Add(colorPanel, wxSizerFlags().Center());

	individualViewPanel->SetSizer(individualViewSizer);
	sizer->Add(individualViewPanel, wxSizerFlags().CenterVertical().DoubleBorder());

}

OutfitDisplay::OutfitDisplay(Outfit* search, wxPanel* panel, wxSizer* sizer) {
	wxPanel* horzPanel = new wxPanel(panel, wxID_ANY);
	wxBoxSizer* horzSizer = new wxBoxSizer(wxHORIZONTAL);
	horzPanel->SetBackgroundColour(wxColour(255, 255, 255));
	if (search->haveTop()) {
		ItemDisplay* topItemDisplay = new ItemDisplay(search->getTop(), horzPanel, horzSizer);
	}
	if (search->haveSuit()) {
		ItemDisplay* suitItemDisplay = new ItemDisplay(search->getSuit(), horzPanel, horzSizer);
	}
	if (search->haveBottom()) {
		ItemDisplay* bottomItemDisplay = new ItemDisplay(search->getBottom(), horzPanel, horzSizer);
	}
	if (search->haveBlazers()) {

		ItemDisplay* blazerItemDisplay = new ItemDisplay(search->getBlazers(), horzPanel, horzSizer);
	}
	horzPanel->SetSizer(horzSizer);
	sizer->Add(horzPanel, wxSizerFlags().Center().DoubleBorder());
}

ResultFrame :: ResultFrame(const wxString& title, vector <Outfit*> allOutfits) 
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{

	// Adding the icon to the frame and the window
	wxIcon icon;
	icon.LoadFile("ficon.ico", wxBITMAP_TYPE_ICO);
	this->SetIcon(icon);
	wxTopLevelWindow::SetIcon(icon);

	wxScrolledWindow* panel = new wxScrolledWindow(this, wxID_ANY);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);


	wxFont titleFont(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_EXTRABOLD);
	wxStaticText* Title = new wxStaticText(panel, wxID_ANY, wxT("Outfit Examples"));
	Title->SetFont(titleFont);
	sizer->Add(Title, wxSizerFlags().TripleBorder().Center());
	
	for (size_t i = 0; i < allOutfits.size() && i < 50; i++){
		OutfitDisplay each(allOutfits[i], panel, sizer);
	}

	panel->SetScrollbars(0, 10, 0, 10);
	panel->SetSizer(sizer);


	// Set the scrolled window as the main window
	SetSizeHints(wxDefaultSize, wxDefaultSize);
	SetSizer(new wxBoxSizer(wxVERTICAL));
	GetSizer()->Add(panel, 1, wxEXPAND);
}
