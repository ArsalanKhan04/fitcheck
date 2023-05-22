#pragma once
#include <wx\wx.h>
#include <iostream>
#include "Search.h"

class ItemDisplay {
public:
	ItemDisplay(Item* item, wxPanel* panel, wxSizer* sizer);
};

class OutfitDisplay
{
public:
	OutfitDisplay(Outfit* search, wxPanel* panel, wxSizer* sizer);
};

class ResultFrame : public wxFrame
{
public:
	ResultFrame(const wxString& title, vector <Outfit*> allOutfits);
};

