#pragma once
#include <iostream>

enum identification {
	top = 6900,
	bottom = 6901,
	socks = 6902,
	shoes = 6903,
	blazer = 6904
};


class Item
{
	std::string id;
	std::string product_title;
	int price;
	std::string brand;
	std::string color;
	int colorhex;
	std::string imageLink;

public:
	Item(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
	std::string getId() const;
	std::string getProductTitle() const;
	int getPrice() const;
	std::string getBrand() const;
	std::string getColor() const;
	int getColorHex() const;
	std::string getImageLink() const;

	virtual identification whatAmI() const = 0;
};

class Bottom : public Item {
	identification whatAmI() const;
};

class Top : public Item {
	identification whatAmI() const;
};

class FormalShirt : public Top {
	std::string fit;
	std::string stuff;
};

class Accessory : public Item {
	identification whatAmI() const;
};

class Blazers : public Item {
	identification whatAmI() const;
};

class Suit : public Top, public Bottom {

};

class Tie : Accessory {

};

class Cufflinks : Accessory {

};

class Socks : Accessory {

};