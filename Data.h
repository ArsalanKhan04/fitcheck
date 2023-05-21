#pragma once
#include "item.h"
#include <vector>

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
	Data();
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
