#pragma once
#include <wx\wx.h>
#include "MyApp.h"
#include "item.h"
#include "Data.h"


class ItemPages {
public:
	template <class T>
	ItemPages(const std::vector<T*, std::allocator<T*>>& itemvec, wxPanel* panel, wxSizer* sizer);
private:

};


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const User* user);
	Data* alldata;
private:

};
