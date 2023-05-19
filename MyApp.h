#pragma once
#include <wx/wx.h>
#include "User.h"


extern User* CurrentUser;

class MyApp: public wxApp
{
private:
public:
	// Called on application startup
	virtual bool OnInit();
};

