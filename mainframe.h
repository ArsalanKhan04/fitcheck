#pragma once
#include <wx\wx.h>
#include "MyApp.h"
#include "item.h"
#include "Data.h"

class IndividualPage {
public:
	IndividualPage(wxPanel* panel, wxSizer* sizer);
private:
	wxPanel* individualViewPanel;
	wxBoxSizer* individualViewSizer;
	wxImage* individualImage;
	wxBitmap* individualBitmapImage;
	wxStaticBitmap* individual_bitmap;
	wxStaticText* individualProductTitle;

	wxStaticText* individualProductPrice;
	wxStaticText* individualProductBrand;
	wxStaticText* individualProductColor;
	wxStaticBitmap* individualProductColorImage;

	wxPanel* colorPanel;
	wxBoxSizer* colorView;

	friend class ItemPages;
	void switchPage (const Item*);
};

class ItemPages {
public:
	template <class T>
	ItemPages(const std::vector<T*, std::allocator<T*>>& itemvec, wxPanel* panel, wxSizer* sizer);
private:
	IndividualPage* rightPage;
};




class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const User* user);
	Data* alldata;
private:

};
