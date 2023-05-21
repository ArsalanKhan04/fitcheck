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

const std::vector<Accessory*>& Data::getBelts() const
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


Data::Data() {
	try {
		// Getting data into act wear bottoms
		sqlite::database db("fitcheck.db");
		Bottom* bottom;
		Top* top;
		Suit* suit;
		Blazers* blazer;
		Tie* tie;
		Cufflinks* cufflink;
		Socks* sock;
		Footwear* footwear;
		PocketSquare* pocketsquare;
		Belts* belt;



		db << "select suit_id, product_title, trouser_type, price, brand, color, colorhex FROM suits;"
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
		db << "select shirt_id, product_title, trouser_type, price, brand, color, colorhex FROM formalshirts;"
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
		db << "select shirt_id, product_title, trouser_type, price, brand, color, colorhex FROM casualshirts;"
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
		db << "select polo_id, product_title, trouser_type, price, brand, color, colorhex FROM polos;"
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
		db << "select blazer_id, product_title, trouser_type, price, brand, color, colorhex FROM blazers;"
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
		db << "select chino_id, product_title, trouser_type, price, brand, color, colorhex FROM chinos;"
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
		db << "select jean_id, product_title, trouser_type, price, brand, color, colorhex FROM jeans;"
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
		db << "select actwearbottom_id, product_title, trouser_type, price, brand, color, colorhex FROM actwearbottoms;"
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
		db << "select dresspants_id, product_title, trouser_type, price, brand, color, colorhex FROM dresspants;"
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
		db << "select shorts_id, product_title, trouser_type, price, brand, color, colorhex FROM shorts;"
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
		db << "select cufflinks_id, product_title, trouser_type, price, brand, color, colorhex FROM cufflinks;"
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
		db << "select socks_id, product_title, trouser_type, price, brand, color, colorhex FROM socks;"
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
		db << "select pocketsquare_id, product_title, trouser_type, price, brand, color, colorhex FROM pocketsquare;"
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
		db << "select tie_id, product_title, trouser_type, price, brand, color, colorhex FROM ties;"
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
		db << "select belt_id, product_title, trouser_type, price, brand, color, colorhex FROM belts;"
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
		db << "select footwear_id, product_title, footwear_type, price, brand, color, colorhex FROM footwear;"
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