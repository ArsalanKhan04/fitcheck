#pragma once
#include <iostream>
using namespace std;
enum identification {
	top = 6900,
	bottom = 6901,
	socks = 6902,
	shoes = 6903,
	blazer = 6904,
	accessory = 6905,
	suit = 6906
};
enum type {
	formal = 0001,
	casual = 0002,
	semi_formal = 0003,
	misc = 0004
};




class Item
{
	std::string category;
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
	virtual type WhatType() const = 0;
};

class Bottom : public Item {
public:
	virtual identification whatAmI() const;
	virtual type WhatType() const;
	Bottom(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
};

class Top : public Item {
public:
	virtual identification whatAmI() const;
	virtual type WhatType() const;
	Top(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
};

class FormalShirt : public Top {
	std::string fit;
	std::string stuff;
public:
	identification whatAmI() const;
	type WhatType() const;
	FormalShirt(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Accessory : public Item {
public:
	identification whatAmI() const;
	type WhatType() const;
	Accessory(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
};

class Blazers : public Top {
	string fit;
	string stuff;
public:
	identification whatAmI() const;
	type WhatType() const;
	Blazers(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Suit : public Top, public Bottom {
	string fit, stuff, Name_type;
public:
	identification whatAmI() const;
	type WhatType() const;
	Suit(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&, const std::string&);
};

class Tie :public Accessory {
	string Name_type;
public:
	identification whatAmI() const;
	type WhatType() const;
	Tie(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class Cufflinks : public Accessory {
	string Name_type;
public:
	identification whatAmI() const;
	type WhatType() const;
	Cufflinks(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class Socks : public Accessory {
	string Name_type, stuff;
public:
	identification whatAmI() const;
	type WhatType() const;
	Socks(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class ActwearBottoms : public Bottom {
public:
	string name_type, stuff;
	identification whatAmI() const;
	type WhatType() const;
	ActwearBottoms(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Belts : public Accessory {
public:
	string name_type;
	identification whatAmI() const;
	type WhatType() const; 
	Belts(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class CasualShirts : public Top {
public:
	string name_type, stuff;
	identification whatAmI() const;
	type WhatType() const;
	CasualShirts(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Chinos : public Bottom {
public:
	string name_type, stuff;
	identification whatAmI() const;
	type WhatType() const;
	Chinos(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class DressPants : public Bottom {
public:
	string name_type, stuff, fit;
	identification whatAmI() const;
	type WhatType() const;
	DressPants(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&, const std::string&);
};

class Footwear : public Accessory {
public:
	string name_type;
	identification whatAmI() const;
	type WhatType() const;
	Footwear(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class Jeans : public Bottom {
public:
	string name_type;
	identification whatAmI() const;
	type WhatType() const;
	Jeans(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class PocketSquare : public Accessory {
public:
	identification whatAmI() const;
	type WhatType() const;
	PocketSquare(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
};

class Polos : public Top {
public:
	string stuff, name_type;
	identification whatAmI() const;
	type WhatType() const;
	Polos(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Shorts : public Bottom {
public:
	string stuff, name_type;
	identification whatAmI() const;
	type WhatType() const;
	Shorts(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};
