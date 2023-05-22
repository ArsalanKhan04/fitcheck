#include "mainframe.h"
#include <wx\notebook.h>
#include <wx\choicebk.h>
#include <wx\statline.h>
#include <type_traits>


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
ItemPages::ItemPages(const std::vector<T*, std::allocator<T*>> &itemvec, wxPanel* panel, wxSizer* sizer, Wardrobe* ward, vector <Item*> searchpageitems) {
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
	wxButton* addButton = nullptr;

	for (const T* eachitem : itemvec) {
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
		viewButton->Bind(wxEVT_BUTTON, [this, &eachitem] (wxCommandEvent& event) {
			rightPage->switchPage(eachitem);
			});
		if (ward != nullptr) {
			addButton = new wxButton(buttonPanel, wxID_ANY, wxT("Add"));
			addButton->Bind(wxEVT_BUTTON, [this, eachitem, ward, addButton](wxCommandEvent& event) {
				ward->add(eachitem->getId(), eachitem->getApparel());
				addButton->SetLabel(wxT("Added"));
				});
		}
		
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

wxPanel* eachElement(Item* item, wxPanel* parentPanel) {
	wxPanel* panel = new wxPanel(parentPanel, wxID_ANY);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	wxImage* image;
	wxBitmap* bitmapImage;
	wxStaticBitmap* m_bitmap;
	wxStaticText* productTitle;
	wxPanel* buttonPanel;
	//Create a wxBitmap for image
	image = new wxImage(item->getImageLinks()[0], wxBITMAP_TYPE_PNG);
	image->Rescale(100, 150);
	bitmapImage = new wxBitmap(*image);
	m_bitmap = new wxStaticBitmap(panel, wxID_ANY, *bitmapImage);
	// Adding it to the individual part
	sizer->Add(m_bitmap, wxSizerFlags().Center().DoubleBorder());
	// Add the Product Name
	productTitle = new wxStaticText(panel, wxID_ANY, wxT("" + item->getProductTitle()), wxDefaultPosition, wxSize(150, -1), wxALIGN_CENTRE_HORIZONTAL);
	sizer->Add(productTitle, wxSizerFlags().Center().DoubleBorder());
	return panel;
}

SearchPage::SearchPage(Search* search, wxPanel* panel, wxSizer* sizer) {
	wxPanel* selectedPanel = new wxPanel(panel, wxID_ANY);
	sizer->Add(selectedPanel, wxSizerFlags().DoubleBorder());
	wxBoxSizer* selectedSizer = new wxBoxSizer(wxHORIZONTAL);
	if (search->haveTop()) {
		Top* top = search->getTop();
		wxPanel* topPanel = eachElement(top, selectedPanel);
		selectedSizer->Add(topPanel, wxSizerFlags().DoubleBorder());
	}
	if (search->haveSuit()) {
		Suit* suit = search->getSuit();
		wxPanel* suitPanel = eachElement(suit, selectedPanel);
		selectedSizer->Add(suitPanel, wxSizerFlags().DoubleBorder());
	}
	if (search->haveBottom()) {
		Bottom* bottom = search->getBottom();
		wxPanel* bottomPanel = eachElement(bottom, selectedPanel);
		selectedSizer->Add(bottomPanel, wxSizerFlags().DoubleBorder());
	}
	if (search->haveTie()) {
		Tie* tie = search->getTie();
		wxPanel* tiePanel = eachElement(tie, selectedPanel);
		selectedSizer->Add(tiePanel, wxSizerFlags().DoubleBorder());
	}
	if (search->haveBelts()) {
		Belts* belts = search->getBelts();
		wxPanel* beltsPanel = eachElement(belts, selectedPanel);
		selectedSizer->Add(beltsPanel, wxSizerFlags().DoubleBorder());
	}
	if (search->haveCufflinks()) {
		Cufflinks* cufflinks = search->getCufflinks();
		wxPanel* cufflinksPanel = eachElement(cufflinks, selectedPanel);
		selectedSizer->Add(cufflinksPanel, wxSizerFlags().DoubleBorder());
	}
	if (search->haveBlazers()) {
		Blazers* blazers = search->getBlazers();
		wxPanel* blazersPanel = eachElement(blazers, selectedPanel);
		selectedSizer->Add(blazersPanel, wxSizerFlags().DoubleBorder());
	}
	if (search->haveSocks()) {
		Socks* socks = search->getSocks();
		wxPanel* socksPanel = eachElement(socks, selectedPanel);
		selectedSizer->Add(socksPanel, wxSizerFlags().DoubleBorder());
	}
	if (search->haveFootwears()) {
		Footwear* footwears = search->getFootwears();
		wxPanel* footwearsPanel = eachElement(footwears, selectedPanel);
		selectedSizer->Add(footwearsPanel, wxSizerFlags().DoubleBorder());
	}
	if (search->havePocketSquare()) {
		PocketSquare* pocketsquare = search->getPocketSquare();
		wxPanel* pocketsquarePanel = eachElement(pocketsquare, selectedPanel);
		selectedSizer->Add(pocketsquarePanel, wxSizerFlags().DoubleBorder());
	}

}




MainFrame::MainFrame(const wxString& title, const User* user) :
	wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(1200,700))
{
	wxLogMessage(wxString(user->getname()));

	alldata = new Data;
	alldata->load();
	wardrobe = new Wardrobe;
	wardrobe->load(user);
	search = new Search;

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
	wxIcon searchIcon;
	searchIcon.LoadFile(wxT("search.ico"), wxBITMAP_TYPE_ICO);
	wxBitmap notebookImage1(closetIcon);
	wxBitmap notebookImage2(cartIcon);
	wxBitmap notebookImage3(searchIcon);
	int panel1img = notebookimages->Add(notebookImage1);
	int panel2img = notebookimages->Add(notebookImage2);
	int panel3img = notebookimages->Add(notebookImage3);

	// Adding pages with their icons
	wxNotebook* mainNotebook = new wxNotebook(mainpanel, wxID_ANY);
	mainNotebook->AssignImageList(notebookimages);
	wxPanel* wardrobePanel = new wxPanel(mainNotebook, wxID_ANY);
	wxPanel* allClothesPanel = new wxPanel(mainNotebook, wxID_ANY);
	wxPanel* searchPanel = new wxPanel(mainNotebook, wxID_ANY);
	mainNotebook->AddPage(wardrobePanel, wxT("Your Wardrobe"), true, panel1img);
	mainNotebook->AddPage(allClothesPanel, wxT("Get More Clothes"), false, panel2img);
	mainNotebook->AddPage(searchPanel, wxT("Complete Outfit"), false, panel3img);
	
	// Creating sizers for wardrobe and all clothes pages
	wxBoxSizer* wardrobeSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* allClothesSizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* searchSizer = new wxBoxSizer(wxVERTICAL);



	// Adding Label for both
	wxFont* labelFont = new wxFont(16, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxStaticText* wardrobeLabel = new wxStaticText(wardrobePanel, wxID_ANY, wxT("Your Wardrobe"));
	wxStaticText* allClothesLabel = new wxStaticText(allClothesPanel, wxID_ANY, wxT("All Clothes"));
	wxStaticText* searchLabel = new wxStaticText(searchPanel, wxID_ANY, wxT("AutoFill Your Outfit!"));
	wardrobeLabel->SetFont(*labelFont);
	allClothesLabel->SetFont(*labelFont);
	searchLabel->SetFont(*labelFont);
	wardrobeSizer->Add(wardrobeLabel, wxSizerFlags().Left().DoubleBorder());
	allClothesSizer->Add(allClothesLabel, wxSizerFlags().Left().DoubleBorder());
	searchSizer->Add(searchLabel, wxSizerFlags().Left().DoubleBorder());
	wxStaticLine* division = new wxStaticLine(wardrobePanel, wxID_ANY);
	wardrobeSizer->Add(division);
	
	// ======================== WARDROBE PAGE HERE =====================

	wxChoicebook* choicepage = new wxChoicebook(wardrobePanel, wxID_ANY);

	// Bottoms
	wxPanel* BottomWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* BottomWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* bottomwarditems = new ItemPages(wardrobe->getBottoms(), BottomWardPanel, BottomWardSizer, nullptr, searchpageitems);
	BottomWardPanel->SetSizer(BottomWardSizer);

	//Tops
	wxPanel* TopWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* TopWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* topwarditems = new ItemPages(wardrobe->getTops(), TopWardPanel, TopWardSizer, nullptr, searchpageitems);
	TopWardPanel->SetSizer(TopWardSizer);

	//Ties
	wxPanel* TieWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* TieWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* tiewarditems = new ItemPages(wardrobe->getTies(), TieWardPanel, TieWardSizer, nullptr, searchpageitems);
	TieWardPanel->SetSizer(TieWardSizer);

	//Belts
	wxPanel* BeltWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* BeltWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* beltwarditems = new ItemPages(wardrobe->getBelts(), BeltWardPanel, BeltWardSizer, nullptr, searchpageitems);
	BeltWardPanel->SetSizer(BeltWardSizer);

	//Cufflinks
	wxPanel* CufflinkWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* CufflinkWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* cufflinkwarditems = new ItemPages(wardrobe->getCufflinks(), CufflinkWardPanel, CufflinkWardSizer, nullptr, searchpageitems);
	CufflinkWardPanel->SetSizer(CufflinkWardSizer);

	//Blazers
	wxPanel* BlazerWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* BlazerWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* blazerwarditems = new ItemPages(wardrobe->getBlazers(), BlazerWardPanel, BlazerWardSizer, nullptr, searchpageitems);
	BlazerWardPanel->SetSizer(BlazerWardSizer);

	//Socks
	wxPanel* SockWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* SockWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* sockwarditems = new ItemPages(wardrobe->getSocks(), SockWardPanel, SockWardSizer, nullptr, searchpageitems);
	SockWardPanel->SetSizer(SockWardSizer);

	//Footwear
	wxPanel* FootwearWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* FootwearWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* footwearitems = new ItemPages(wardrobe->getFootwears(), FootwearWardPanel, FootwearWardSizer, nullptr, searchpageitems);
	FootwearWardPanel->SetSizer(FootwearWardSizer);

	//PocketSquare
	wxPanel* PocketsquareWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* PocketsquareWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* pocketsquarewarditems = new ItemPages(wardrobe->getPocketsquares(), PocketsquareWardPanel, PocketsquareWardSizer, nullptr, searchpageitems);
	PocketsquareWardPanel->SetSizer(PocketsquareWardSizer);

	//Suit
	wxPanel* SuitWardPanel = new wxPanel(choicepage, wxID_ANY);
	wxBoxSizer* SuitWardSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* suitwarditems = new ItemPages(wardrobe->getSuits(), SuitWardPanel, SuitWardSizer, nullptr, searchpageitems);
	SuitWardPanel->SetSizer(SuitWardSizer);

	choicepage->AddPage(BottomWardPanel, "Bottoms");
	choicepage->AddPage(TopWardPanel, "Tops");
	choicepage->AddPage(TieWardPanel, "Ties");
	choicepage->AddPage(BeltWardPanel, "Belts");
	choicepage->AddPage(CufflinkWardPanel, "Cufflinks");
	choicepage->AddPage(BlazerWardPanel, "Blazers");
	choicepage->AddPage(SockWardPanel, "Socks");
	choicepage->AddPage(FootwearWardPanel, "Footwears");
	choicepage->AddPage(PocketsquareWardPanel, "Pocketsquares");
	choicepage->AddPage(SuitWardPanel, "Suits");

	//adding the whole view to the wardrobe
	wardrobeSizer->Add(choicepage, wxSizerFlags().Expand().DoubleBorder());

	// ========================= ALL PAGE HERE ======================


	// Adding the all view
	wxChoicebook* choiceall = new wxChoicebook(allClothesPanel, wxID_ANY);

	// Bottoms
	wxPanel* BottomAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* BottomAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* bottomAllitems = new ItemPages(alldata->getBottoms(), BottomAllPanel, BottomAllSizer, wardrobe, searchpageitems);
	BottomAllPanel->SetSizer(BottomAllSizer);

	//Tops
	wxPanel* TopAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* TopAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* topallitems = new ItemPages(alldata->getTops(), TopAllPanel, TopAllSizer, wardrobe, searchpageitems);
	TopAllPanel->SetSizer(TopAllSizer);

	//Ties
	wxPanel* TieAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* TieAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* tieallitems = new ItemPages(alldata->getTies(), TieAllPanel, TieAllSizer, wardrobe, searchpageitems);
	TieAllPanel->SetSizer(TieAllSizer);

	//Belts
	wxPanel* BeltAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* BeltAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* beltallitems = new ItemPages(alldata->getBelts(), BeltAllPanel, BeltAllSizer, wardrobe, searchpageitems);
	BeltAllPanel->SetSizer(BeltAllSizer);

	//Cufflinks
	wxPanel* CufflinkAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* CufflinkAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* cufflinkallitems = new ItemPages(alldata->getCufflinks(), CufflinkAllPanel, CufflinkAllSizer, wardrobe, searchpageitems);
	CufflinkAllPanel->SetSizer(CufflinkAllSizer);

	//Blazers
	wxPanel* BlazerAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* BlazerAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* blazerallitems = new ItemPages(alldata->getBlazers(), BlazerAllPanel, BlazerAllSizer, wardrobe, searchpageitems);
	BlazerAllPanel->SetSizer(BlazerAllSizer);

	//Socks
	wxPanel* SockAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* SockAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* sockallitems = new ItemPages(alldata->getSocks(), SockAllPanel, SockAllSizer, wardrobe, searchpageitems);
	SockAllPanel->SetSizer(SockAllSizer);

	//Footwear
	wxPanel* FootwearAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* FootwearAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* footwearallitems = new ItemPages(alldata->getFootwears(), FootwearAllPanel, FootwearAllSizer, wardrobe, searchpageitems);
	FootwearAllPanel->SetSizer(FootwearAllSizer);

	//PocketSquare
	wxPanel* PocketsquareAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* PocketsquareAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* pocketsquareallitems = new ItemPages(alldata->getPocketsquares(), PocketsquareAllPanel, PocketsquareAllSizer, wardrobe, searchpageitems);
	PocketsquareAllPanel->SetSizer(PocketsquareAllSizer);

	//Suit
	wxPanel* SuitAllPanel = new wxPanel(choiceall, wxID_ANY);
	wxBoxSizer* SuitAllSizer = new wxBoxSizer(wxHORIZONTAL);
	ItemPages* suitallitems = new ItemPages(alldata->getSuits(), SuitAllPanel, SuitAllSizer, wardrobe, searchpageitems);
	SuitAllPanel->SetSizer(SuitAllSizer);

	choiceall->AddPage(BottomAllPanel, "Bottoms");
	choiceall->AddPage(TopAllPanel, "Tops");
	choiceall->AddPage(TieAllPanel, "Ties");
	choiceall->AddPage(BeltAllPanel, "Belts");
	choiceall->AddPage(CufflinkAllPanel, "Cufflinks");
	choiceall->AddPage(BlazerAllPanel, "Blazers");
	choiceall->AddPage(SockAllPanel, "Socks");
	choiceall->AddPage(FootwearAllPanel, "Footwears");
	choiceall->AddPage(PocketsquareAllPanel, "Pocketsquares");
	choiceall->AddPage(SuitAllPanel, "Suits");
	


	allClothesSizer->Add(choiceall, wxSizerFlags().Expand().DoubleBorder());


	// ================ SEARCH PAGE HERE ===============
	wxButton* refresh = new wxButton(searchPanel, wxID_ANY);
	refresh->Bind(wxEVT_BUTTON, [this, searchPanel, searchSizer](wxCommandEvent& evt) {
		searchpage->~SearchPage();
		searchpage = new SearchPage(search, searchPanel, searchSizer);
		});
	searchpage = new SearchPage(search, searchPanel, searchSizer);


	// Assigning sizers for each panel of the notebook
	wardrobePanel->SetSizer(wardrobeSizer);
	allClothesPanel->SetSizer(allClothesSizer);
	searchPanel->SetSizer(searchSizer);


	// Assigning sizer for main panel
	mainPanelSizer->Add(mainNotebook, wxSizerFlags().Expand());
	mainpanel->SetSizer(mainPanelSizer);

	// Assigning sizer for main window
	topsizer->Add(mainpanel, wxSizerFlags().Expand());
	SetSizer(topsizer);
	
}