#include "Data.h"
#include "item.h"
#include <sqlite_modern_cpp.h>
#include <iostream>
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/log.h>

const std::vector<Bottom*>& Data::getBottoms() const
{
	return bottoms;
}

const std::vector<Top*>& Data::getTops() const
{
	return tops;
}

const std::vector<Tie*>& Data::getTies() const
{
	return ties;
}

const std::vector<Belts*>& Data::getBelts() const
{
	return belts;
}

const std::vector<Cufflinks*>& Data::getCufflinks() const
{
	return cufflinks;
}

const std::vector<Blazers*>& Data::getBlazers() const
{
	return blazers;
}

const std::vector<Socks*>& Data::getSocks() const
{
	return socks;
}

const std::vector<Footwear*>& Data::getFootwears() const
{
	return footwears;
}

const std::vector<PocketSquare*>& Data::getPocketsquares() const
{
	return pocketsquares;
}

const std::vector<Suit*>& Data::getSuits() const
{
	return suits;
}

void Data::loadSuits(sqlite::database& db, const std::string& cond) {

	Suit* suit = nullptr;
	std::string sqlstatement = "select suit_id, product_title, trouser_type, price, brand, color, colorhex FROM suits";
	sqlstatement += " where ";
	sqlstatement += cond;
	sqlstatement += ";";
	db << sqlstatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		suit = new Suit(id, product_title, price, brand, color, hex, "Normal", "Normal", trouser_type);

		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			suit->Item::addImageLink(address);
		};


		suits.push_back(suit);
	};
};
void Data::loadFormalShirts(sqlite::database& db, const std::string& cond) {
	Top* top = nullptr;
	std::string sqlstatement = "select shirt_id, product_title, trouser_type, price, brand, color, colorhex FROM formalshirts";
	sqlstatement += " where ";
	sqlstatement += cond;
	sqlstatement += ";";
	db <<  sqlstatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		top = new FormalShirt(id, product_title, price, brand, color, hex, "Normal", trouser_type);

		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			top->Item::addImageLink(address);
		};

		tops.push_back(top);
	};
};
void Data::loadCasualShirts(sqlite::database& db, const std::string& cond) {
	Top* top = nullptr;
	std::string sqlstatement = "select shirt_id, product_title, trouser_type, price, brand, color, colorhex FROM casualshirts";
	sqlstatement += " where ";
	sqlstatement += cond;
	sqlstatement += ";";
	db << sqlstatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		top = new CasualShirts(id, product_title, price, brand, color, hex, "Normal", trouser_type);

		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			top->Item::addImageLink(address);
		};

		tops.push_back(top);
	};
};
void Data::loadPolos(sqlite::database& db, const std::string& cond) {
	Top* top = nullptr;
	std::string sqlStatement = "select polo_id, product_title, trouser_type, price, brand, color, colorhex FROM polos";
	sqlStatement += " where ";
	sqlStatement += cond;
	sqlStatement += ";";

	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		top = new Polos(id, product_title, price, brand, color, hex, "Normal", trouser_type);

		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			top->Item::addImageLink(address);
		};


		tops.push_back(top);
	};
}
void Data::loadBlazers(sqlite::database& db, const std::string& cond) {
	Blazers* blazer = nullptr;
	std::string sqlStatement = "SELECT blazer_id, product_title, trouser_type, price, brand, color, colorhex FROM blazers";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";

	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		blazer = new Blazers(id, product_title, price, brand, color, hex, "Normal", trouser_type);

		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			blazer->Item::addImageLink(address);
		};

		blazers.push_back(blazer);
	};
};
void Data::loadChinos(sqlite::database& db, const std::string& cond) {
	Bottom* bottom = nullptr;
	std::string sqlStatement = "SELECT chino_id, product_title, trouser_type, price, brand, color, colorhex FROM chinos";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";

	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		bottom = new Chinos(id, product_title, price, brand, color, hex, trouser_type, "normal");

		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			bottom->Item::addImageLink(address);
		};

		bottoms.push_back(bottom);
	};
};
void Data::loadJeans(sqlite::database& db, const std::string& cond) {
	Bottom* bottom = nullptr;
	std::string sqlStatement = "SELECT jean_id, product_title, trouser_type, price, brand, color, colorhex FROM jeans";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";

	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		bottom = new Jeans(id, product_title, price, brand, color, hex, trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			bottom->Item::addImageLink(address);
		};
		bottoms.push_back(bottom);
	};
};
void Data::loadActwearBottoms(sqlite::database& db, const std::string& cond) {
	Bottom* bottom = nullptr; 
	std::string sqlStatement = "SELECT actwearbottom_id, product_title, trouser_type, price, brand, color, colorhex FROM actwearbottoms";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";

	db << sqlStatement 
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		bottom = new ActwearBottoms(id, product_title, price, brand, color, hex, "Normal", trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			bottom->Item::addImageLink(address);
		};
		bottoms.push_back(bottom);
	};
};
void Data::loadDressPants(sqlite::database& db, const std::string& cond) {
	Bottom* bottom = nullptr;
	std::string sqlStatement = "SELECT dresspants_id, product_title, trouser_type, price, brand, color, colorhex FROM dresspants";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";

	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		bottom = new DressPants(id, product_title, price, brand, color, hex, "Normal", "Normal", trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			bottom->Item::addImageLink(address);
		};
		bottoms.push_back(bottom);
	};
};
void Data::loadShorts(sqlite::database& db, const std::string& cond) {
	Bottom* bottom = nullptr;
	std::string sqlStatement = "SELECT shorts_id, product_title, trouser_type, price, brand, color, colorhex FROM shorts";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";

	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		bottom = new Shorts(id, product_title, price, brand, color, hex, "Normal", trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			bottom->Item::addImageLink(address);
		};
		bottoms.push_back(bottom);
	};
};
void Data::loadCufflinks(sqlite::database& db, const std::string& cond) {
	Cufflinks* cufflink = nullptr;
	std::string sqlStatement = "select cufflinks_id, product_title, trouser_type, price, brand, color, colorhex FROM cufflinks";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";

	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		cufflink = new Cufflinks(id, product_title, price, brand, color, hex, trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			cufflink->Item::addImageLink(address);
		};
		cufflinks.push_back(cufflink);
	};
};
void Data::loadSocks(sqlite::database& db, const std::string& cond) {
	Socks* sock = nullptr;
	std::string sqlStatement = "select socks_id, product_title, trouser_type, price, brand, color, colorhex FROM socks";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";
	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		sock = new Socks(id, product_title, price, brand, color, hex, "Normal", trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			sock->Item::addImageLink(address);
		};
		socks.push_back(sock);
	};
};
void Data::loadPocketSquares(sqlite::database& db, const std::string& cond) {
	PocketSquare* pocketsquare = nullptr;
	std::string sqlStatement = "select pocketsquare_id, product_title, trouser_type, price, brand, color, colorhex FROM pocketsquare";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";
	db << sqlStatement 
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);
		pocketsquare = new PocketSquare(id, product_title, price, brand, color, hex);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			pocketsquare->Item::addImageLink(address);
		};
		pocketsquares.push_back(pocketsquare);
	};
};
void Data::loadTies(sqlite::database& db, const std::string& cond) {
	
	Tie* tie = nullptr;
	std::string sqlStatement = "select tie_id, product_title, trouser_type, price, brand, color, colorhex FROM ties";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";
	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);;
		tie = new Tie(id, product_title, price, brand, color, hex, trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			tie->Item::addImageLink(address);
		};
		ties.push_back(tie);
	};
};
void Data::loadBelts(sqlite::database& db, const std::string& cond) {
	Belts* belt = nullptr;
	std::string sqlStatement = "select belt_id, product_title, trouser_type, price, brand, color, colorhex FROM belts";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";
	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);;
		belt = new Belts(id, product_title, price, brand, color, hex, trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			belt->Item::addImageLink(address);
		};
		belts.push_back(belt);
	};
};
void Data::loadFootwears(sqlite::database& db, const std::string& cond) {
	Footwear* footwear = nullptr;
	std::string sqlStatement = "select footwear_id, product_title, footwear_type, price, brand, color, colorhex FROM footwear";
	sqlStatement += " WHERE ";
	sqlStatement += cond;
	sqlStatement += ";";
	db << sqlStatement
		>> [&](std::string id, std::string product_title, std::string trouser_type, std::string price, std::string brand, std::string color, std::string colorhex) {
		// Remove the '#' character
		colorhex = colorhex.substr(1);
		int hex = std::stoi(colorhex, nullptr, 16);;
		footwear = new Footwear(id, product_title, price, brand, color, hex, trouser_type);
		// getting pictures too
		db << "select address from pictures where item_id = ?" << id
			>> [&](std::string address) {
			footwear->Item::addImageLink(address);
		};
		footwears.push_back(footwear);
	};
};



void Data::load() {
	try {
		// Getting data into act wear bottoms
		sqlite::database db("fitcheck.db");
		
		loadSuits(db, "true");
		loadFormalShirts(db, "true");
		loadCasualShirts(db, "true");
		loadPolos(db, "true");
		loadBlazers(db, "true");
		loadChinos(db, "true");
		loadJeans(db, "true");
		loadActwearBottoms(db, "true");
		loadDressPants(db, "true");
		loadShorts(db, "true");
		loadCufflinks(db, "true");
		loadSocks(db, "true");
		loadPocketSquares(db, "true");
		loadTies(db, "true");
		loadBelts(db, "true");
		loadFootwears(db, "true");
		
	}
	catch (const sqlite::sqlite_exception& e) {
		wxString errorMsg = wxString::FromUTF8(e.what());
		wxString sqlStatement = wxString::FromUTF8(e.get_sql());

		wxMessageDialog alert(nullptr, errorMsg, "Error");
		alert.ShowModal();


		wxMessageDialog alert3(nullptr, sqlStatement, "Error");
		alert3.ShowModal();

	}

	catch (const exception& e) {
		wxMessageDialog alert(nullptr, e.what(), "Error");
		alert.ShowModal();
	}

}
void Data::unload() {
	bottoms.clear();
	tops.clear();
	ties.clear();
	belts.clear();
	cufflinks.clear();
	blazers.clear();
	socks.clear();
	footwears.clear();
	pocketsquares.clear();
	suits.clear();
}

void Wardrobe::load() {
	wxMessageDialog alert(nullptr, "USE LOAD WITH User!", "Error");
	alert.ShowModal();
}

void Wardrobe::load(const User* user) {
	user_id = user->getid();
	this->user = user;
	try {
		// Getting data into act wear bottoms
		sqlite::database db("fitcheck.db");

		// Getting Suit Ids
		int x;
		std::string product_id;
		for (x = app_suit; x <= app_footwears; x+=1) {
			wxString currnum;
			currnum << x;
			wxString currid;
			currid << user_id;
			db << "SELECT product_id FROM wardrobe WHERE user_id = ? AND type = ?;"
				<< user->getid()
				<< x
				>> [&](std::string retrieved_id) {
				product_id = retrieved_id;
				if (x == app_suit){
					std::string condition = "suit_id = '" + product_id + "'";
					loadSuits(db, condition);
				}
				else if (x == app_formalshirts) {
					std::string condition = "shirt_id = '" + product_id + "'";
					loadFormalShirts(db, condition);
				}
				else if (x == app_casualshirts) {
					std::string condition = "shirt_id = '" + product_id + "'";
					loadCasualShirts(db, condition);
				}
				else if (x == app_polos) {
					std::string condition = "polo_id = '" + product_id + "'";
					loadPolos(db, condition);
				}
				else if (x == app_blazers) {
					std::string condition = "blazer_id = '" + product_id + "'";
					loadBlazers(db, condition);
				}
				else if (x == app_chinos) {
					std::string condition = "chino_id = '" + product_id + "'";
					loadChinos(db, condition);
				}
				else if (x == app_jeans) {
					std::string condition = "jean_id = '" + product_id + "'";
					loadJeans(db, condition);
				}
				else if (x == app_actwearbottoms) {
					std::string condition = "actwearbottom_id = '" + product_id + "'";
					loadActwearBottoms(db, condition);
				}
				else if (x == app_dresspants) {
					std::string condition = "dresspants_id = '" + product_id + "'";
					loadDressPants(db, condition);
				}
				else if (x == app_shorts) {
					std::string condition = "shorts_id = '" + product_id + "'";
					loadShorts(db, condition);
				}
				else if (x == app_cufflinks) {
					std::string condition = "cufflinks_id = '" + product_id + "'";
					loadCufflinks(db, condition);
				}
				else if (x == app_socks) {
					std::string condition = "socks_id = '" + product_id + "'";
					loadSocks(db, condition);
				}
				else if (x == app_pocketsquares) {
					std::string condition = "pocketsquare_id = '" + product_id + "'";
					loadPocketSquares(db, condition);
				}
				else if (x == app_ties) {
					std::string condition = "tie_id = '" + product_id + "'";
					loadTies(db, condition);
				}
				else if (x == app_belts) {
					std::string condition = "belt_id = '" + product_id + "'";
					loadBelts(db, condition);
				}
				else if (x == app_footwears) {
					std::string condition = "footwear_id = '" + product_id + "'";
					loadFootwears(db, condition);
				}
			};
		}
		

	}
	catch (const sqlite::sqlite_exception& e) {
		wxString errorMsg = wxString::FromUTF8(e.what());
		wxString sqlStatement = wxString::FromUTF8(e.get_sql());

		wxMessageDialog alert(nullptr, errorMsg, "Error");
		alert.ShowModal();


		wxMessageDialog alert3(nullptr, sqlStatement, "Error");
		alert3.ShowModal();

	}

	catch (const exception& e) {
		wxMessageDialog alert(nullptr, e.what(), "Error");
		alert.ShowModal();
	}
}

void Wardrobe::add(const std::string& product_id, int product_type) {
	try {
		sqlite::database db("fitcheck.db");
		db << "INSERT INTO wardrobe (user_id, type, product_id) VALUES (?, ?, ?);"
			<< user_id
			<< product_type
			<< product_id;
	}
	catch (const sqlite::sqlite_exception& e) {
		wxString errorMsg = wxString::FromUTF8(e.what());
		wxString sqlStatement = wxString::FromUTF8(e.get_sql());

		wxMessageDialog alert(nullptr, errorMsg, "Error");
		alert.ShowModal();


		wxMessageDialog alert3(nullptr, sqlStatement, "Error");
		alert3.ShowModal();

	}

	catch (const exception& e) {
		wxMessageDialog alert(nullptr, e.what(), "Error");
		alert.ShowModal();
	}
	this->unload();
	this->load(user);
}

