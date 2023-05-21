#pragma once
#include "item.h"
#include "User.h"
#include <vector>
#include <sqlite_modern_cpp.h>
#include <iostream>

class Data
{
private:
	std::vector<Bottom*> bottoms;
	std::vector<Top*> tops;
	std::vector<Tie*> ties;
	std::vector<Accessory*> belts; // TO be changed
	std::vector<Cufflinks*> cufflinks;
	std::vector<Blazers*> blazers;
	std::vector<Socks*> socks;
	std::vector<Footwear*> footwears; // TO be changed
	std::vector<PocketSquare*> pocketsquares; // To be changed
	std::vector<Suit*> suits;

public:

	// load functions
	void loadSuits(sqlite::database& db, const std::string& cond);
	void loadFormalShirts(sqlite::database& db, const std::string& cond);
	void loadCasualShirts(sqlite::database& db, const std::string& cond);
	void loadPolos(sqlite::database& db, const std::string& cond);
	void loadBlazers(sqlite::database& db, const std::string& cond);
	void loadChinos(sqlite::database& db, const std::string& cond);
	void loadJeans(sqlite::database& db, const std::string& cond);
	void loadActwearBottoms(sqlite::database& db, const std::string& cond);
	void loadDressPants(sqlite::database& db, const std::string& cond);
	void loadShorts(sqlite::database& db, const std::string& cond);
	void loadCufflinks(sqlite::database& db, const std::string& cond);
	void loadSocks(sqlite::database& db, const std::string& cond);
	void loadPocketSquares(sqlite::database& db, const std::string& cond);
	void loadTies(sqlite::database& db, const std::string& cond);
	void loadBelts(sqlite::database& db, const std::string& cond);
	void loadFootwears(sqlite::database& db, const std::string& cond);




	void load();
	// Getter functions
	const std::vector<Bottom*>& getBottoms() const;
	const std::vector<Top*>& getTops() const;
	const std::vector<Tie*>& getTies() const;
	const std::vector<Accessory*>& getBelts() const;
	const std::vector<Cufflinks*>& getCufflinks() const;
	const std::vector<Blazers*>& getBlazers() const;
	const std::vector<Socks*>& getSocks() const;
	const std::vector<Footwear*>& getFootwears() const;
	const std::vector<PocketSquare*>& getPocketsquares() const;
	const std::vector<Suit*>& getSuits() const;

};

class Wardrobe :public Data {
public:
	void load();
	void load(User* user);
};