#pragma once
#include <wx\wx.h>
#include "MyApp.h"
#include "item.h"
#include "Data.h"
#include "Search.h"

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
	ItemPages(const std::vector<T*, std::allocator<T*>>& itemvec, wxPanel* panel, wxSizer* sizer, Wardrobe* ward, Search* search);
private:
	IndividualPage* rightPage;
};


class EachElem {
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
public:
	EachElem(wxPanel* panel, wxSizer* sizer, const wxString& title);
	void switchPage(const Item*);
};

wxPanel* eachElement(Item* item, wxPanel* parentPanel);

class SearchPage {
public:
	SearchPage(Search* search, wxPanel* panel, wxSizer* sizer);
	void refreshSearch();
private:
	Search* search;
	EachElem* topsearch;
	EachElem* bottomsearch;
	EachElem* suitsearch;
	EachElem* tiesearch;
	EachElem* beltsearch;
	EachElem* cufflinksearch;
	EachElem* blazersearch;
	EachElem* socksearch;
	EachElem* footwearsearch;
	EachElem* pocketsquaresearch;
};


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const User* user);
	Data* alldata;
	Wardrobe* wardrobe;
	Search* search;
	SearchPage* searchpage;
	vector<Item*> searchpageitems;
private:

};
