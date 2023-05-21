#pragma once
#include <iostream>
#include "Weight.h"
using namespace std;
enum identification {
	top = 6900,
	bottom = 6901,
	socks = 6902,
	shoes = 6903,
	blazer = 6904,
	accessory = 6905,
	suit = 6906,
	jeans = 6907,
	Dress_pants = 6908,
	chinos = 6909,
	Formal_Shirt = 6910,
	Casual_shirt = 6911, 
	Active_bottom = 6912,


};
enum type {
	formal = 0001,
	casual = 0002,
	semi_formal = 0003,
	misc = 0004
};
enum class Color : uint32_t {
	d_brown = 0x654321,
	sky_blue = 0x87CEEB,
	light_black = 0x3A3A3A,
	blue_white_verdel_stripe = 0x87CEEB,
	lilac = 0xC8A2C8,
	magenta_blue = 0xFF00FF,
	copper_brown = 0xB87333,
	purple_grey = 0xA9A9A9,
	blue_pink_shirt = 0x87CEEB,
	yellow = 0xFFFF00,
	ink_blue = 0x4B0082,
	navy_orange = 0x000080,
	heather_green = 0x006400,
	navy_white_stripes = 0x000080,
	burgundy = 0x800020,
	heather_denim_blue = 0x6F8FAF,
	green_black = 0x006400,
	grey_tartan = 0x808080,
	charcoal = 0x36454F,
	classic_blue = 0x0F4C81,
	malaysia = 0xCC0000,
	d_grey = 0x696969,
	blue_bayadere = 0x1F4788,
	dark_olive = 0x556B2F,
	silver_grey = 0xC0C0C0,
	heather_burgundy = 0x8F0000,
	sky_blue_white = 0x87CEEB,
	light_cream = 0xF8F8FF,
	mason_sky_blue = 0x87CEEB,
	sea_blue = 0x006994,
	white_red_tattersall = 0xFFFFFF,
	black_silver = 0x545454,
	lavender_grey = 0xC4C3D0,
	maroon = 0x800000,
	light_blue_textured = 0x87CEEB,
	blue_white = 0x87CEEB,
	light_black = 0x2F4F4F,
	pepper = 0x2E2E2E,
	brown_orange = 0xA52A2A,
	brown = 0xA52A2A,
	l_grey = 0xC0C0C0,
	awning_blue = 0x2B3856,
	jet_black = 0x000000,
	light_blue = 0x87CEEB,
	light_brown = 0xB5651D,
	staller = 0xFDD7E4,
	maroon_white = 0x800000,
	dye_blue = 0x002366,
	camel = 0xC19A6B,
	red = 0xFF0000,
	tan = 0xD2B48C,
	grey_blue = 0x6B8E23,
	solid_maroon = 0x800000,
	navy_white = 0x000080,
	white_blue_dotted_stripe = 0x87CEEB,
	d_grey_silver = 0x808080,
	red_white = 0xFF0000,
	l_green = 0x32CD32,
	brown_tartan = 0x964B00,
	multicolor_bayadere = 0xFF0000,
	sky_red = 0xFF0000,
	ash_grey = 0xB2BEB5,
	blue = 0x0000FF,
	white_l_purple = 0xFFFFFF,
	sky_blue_check = 0x87CEEB,
	solid_turquoise = 0x40E0D0,
	blue_brown = 0xA52A2A,
	black_green = 0x006400,
	mason_blue = 0x87CEEB,
	coffee = 0x6F4E37,
	royal_blue = 0x4169E1,
	grey = 0x808080,
	brown_black = 0xA52A2A,
	greyish_blue = 0x5E8AA8,
	heather_burgundy = 0x800000,
	vetliver = 0x507030,
	burgandy = 0x800020,
	navy = 0x000080,
	dark_grey = 0xA9A9A9,
	black_navy_blue = 0x000080,
	olive = 0x808000,
	light_grey = 0xD3D3D3,
	sky_blue_plain = 0x87CEEB,
	black_white = 0x000000,
	navy_blue = 0x000080,
	vetiver = 0x556B2F,
	navy_blue = 0x000080,
	black_l_grey = 0x000000,
	brown_yellow = 0xB8860B,
	black_brown = 0x000000,
	black_textured = 0x000000,
	charcoal_check = 0x36454F,
	heather_grey = 0x808080,
	green = 0x008000,
	oxford_blue = 0x002147,
	classic_blue_check = 0x0F4C81,
	black = 0x000000,
	light_purple = 0xB19CD9,
	fuchsia = 0xFF00FF,
	cream = 0xFFFDD0,
	m_blue = 0x0000FF,
	black_uni = 0x000000,
	light_beige = 0xF5F5DC,
	turquoise = 0x40E0D0,
	d_blue = 0x0000FF,
	dark_khaki = 0xBDB76B,
	grey_silver = 0xC0C0C0,
	purple = 0x800080,
	rinse = 0x002147,
	light_pink = 0xFFB6C1,
	blue_pink = 0xFFC0CB,
	aqua_blue = 0x00FFFF,
	blue_coral_navy = 0x0000FF,
	white = 0xFFFFFF,
	blue_black = 0x000080,
	blue_white_yellow = 0x87CEEB,
	d_navy = 0x000080,
	dark_green = 0x006400,
	red_orange = 0xFF4500,
	dark_navy = 0x000080,
	palm = 0x7CFC00,
	khaki = 0xC3B091,
	silver = 0xC0C0C0,
	dark_blue = 0x00008B,
	wheat = 0xF5DEB3,
	white_blue = 0xFFFFFF,
	white_purple = 0xFFFFFF,
	navy_dupplin = 0x000080,
	white_blue_pencil_stripe = 0x87CEEB,
	dark_brown = 0x654321,
	golden = 0xFFD700,
	black_red = 0x000000,
	maroon_brown = 0x800000,
	beige = 0xF5F5DC,
	white_navy = 0xFFFFFF,
	dawn_blue = 0x7BA9DD,
	white_l_blue = 0xFFFFFF,
	aqua_check = 0x00FFFF,
	navy_red = 0x000080,
	black_tan = 0x000000,
	light_brown = 0xB5651D,
	blue_white_dual = 0x87CEEB,
	light_olive = 0x808000,
	off_white = 0xFAF0E6,
};



class Item
{
	std::string category;
	std::string id;
	std::string product_title;
	int price;
	std::string brand;
	std::string color;
	Color colorhex;
	std::string imageLink;

public:
	double operator + (Item& I1)
	{
		return (double)this->colorhex + (double)I1.colorhex;
	}
	double operator - (Item& I1)
	{
		return (double)this->colorhex - (double)I1.colorhex;
	}
	friend class Weight;
	Item(const std::string&, const std::string&, int, const std::string&, const std::string&, Color, const std::string&);
	std::string getId() const;
	std::string getProductTitle() const;
	int getPrice() const;
	std::string getBrand() const;
	std::string getColor() const;
	Color getColorHex() const;
	std::string getImageLink() const;

	virtual identification whatAmI() const = 0;
	virtual type WhatType() const = 0;
};

class Bottom : public Item {
public:
	Bottom(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
	friend class Weight;
};

class Top : public Item {
public:
	Top(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
	friend class Weight;
};

class FormalShirt : public Top {
	std::string fit;
	std::string stuff;
public:
	identification whatAmI() const;
	type WhatType() const;
	FormalShirt(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
	friend class Weight;
};

class Accessory : public Item {
public:
	identification whatAmI() const;
	type WhatType() const;
	Accessory(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
	friend class Weight;
};

class Blazers : public Top {
	string fit;
	string stuff;
public:
	friend class Weight;
	identification whatAmI() const;
	type WhatType() const;
	Blazers(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Suit : public Top, public Bottom {
	
	string fit, stuff, Name_type;
public:
	friend class Weight;
	identification whatAmI() const;
	type WhatType() const;
	Suit(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&, const std::string&);
};

class Tie :public Accessory {
	
	string Name_type;
public:
	friend class Weight;
	identification whatAmI() const;
	type WhatType() const;
	Tie(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class Cufflinks : public Accessory {
	
	string Name_type;
public:
	friend class Weight;
	identification whatAmI() const;
	type WhatType() const;
	Cufflinks(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class Socks : public Accessory {
	
	string Name_type, stuff;
public:
	friend class Weight;
	identification whatAmI() const;
	type WhatType() const;
	Socks(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class ActwearBottoms : public Bottom {
	
public:
	friend class Weight;
	string name_type, stuff;
	identification whatAmI() const;
	type WhatType() const;
	ActwearBottoms(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Belts : public Accessory {
	
public:
	friend class Weight;
	string name_type;
	identification whatAmI() const;
	type WhatType() const; 
	Belts(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class CasualShirts : public Top {
	
public:
	friend class Weight;
	string name_type, stuff;
	identification whatAmI() const;
	type WhatType() const;
	CasualShirts(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Chinos : public Bottom {
	
public:
	friend class Weight;
	string name_type, stuff;
	identification whatAmI() const;
	type WhatType() const;
	Chinos(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class DressPants : public Bottom {
	
public:
	friend class Weight;
	string name_type, stuff, fit;
	identification whatAmI() const;
	type WhatType() const;
	DressPants(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&, const std::string&);
};

class Footwear : public Accessory {
	
public:
	friend class Weight;
	string name_type;
	identification whatAmI() const;
	type WhatType() const;
	Footwear(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class Jeans : public Bottom {
	
public:
	friend class Weight;
	string name_type;
	identification whatAmI() const;
	type WhatType() const;
	Jeans(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&);
};

class PocketSquare : public Accessory {
	
public:
	friend class Weight;
	identification whatAmI() const;
	type WhatType() const;
	PocketSquare(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&);
};

class Polos : public Top {
	
public:
	friend class Weight;
	string stuff, name_type;
	identification whatAmI() const;
	type WhatType() const;
	Polos(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};

class Shorts : public Bottom {
	
public:
	friend class Weight;
	string stuff, name_type;
	identification whatAmI() const;
	type WhatType() const;
	Shorts(const std::string&, const std::string&, int, const std::string&, const std::string&, int, const std::string&, const std::string&, const std::string&);
};
