#pragma once
#include "item.h"
using namespace std;
class Item;
class Weight
{
	int formal_weight;
	int casual_weight;
	int Semi_formal_weight;
	int misc_weight;
	int contrast;
	int matching;
	
public:
	Weight(Item&, Item&);
	Weight();
	Weight(const Weight& other);

	Weight operator+(const Weight& other) const;
	Weight operator/(int num) const;
	int getFormalWeight() const;
	int getCasualWeight() const;
	int getSemiFormalWeight() const;
	int getMiscWeight() const;
	int getContrast() const;
	int getMatching() const;
};
