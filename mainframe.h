#pragma once
#include <wx\wx.h>
#include "MyApp.h"
#include "item.h"


class ItemPages {
public:
	ItemPages(std::vector<Item>&);
private:

};


class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title, const User* user);
private:

};