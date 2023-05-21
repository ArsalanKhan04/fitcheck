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

	
};
