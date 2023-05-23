#include "item.h"
using namespace std;
Item::Item(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex) {
    this->id = id;
    this->product_title = product_title;
    this->price = price;
    this->brand = brand;
    this->color = color;
    this->colorhex = colorhex;
    this->imageLink = "";
}

std::string Item::getId() const {
    return id;
}

std::string Item::getProductTitle() const {
    return product_title;
}

std::string Item::getPrice() const {
    return price;
}

std::string Item::getBrand() const {
    return brand;
}

std::string Item::getColor() const {
    return color;
}

int Item::getColorHex() const {
    return colorhex;
}

std::string Item::getImageLink() const {
    return imageLink;
}
vector <std::string> Item::getImageLinks() const {
    return imageLinks;
}

void Item::addImageLink(const std::string& s) {
    imageLinks.push_back(s);
}

// Identification for derived items

identification FormalShirt::whatAmI() const
{
    return top;
}
int FormalShirt::getApparel() const {
    return app_formalshirts;
}

identification Accessory::whatAmI() const
{
    return accessory;
}

identification Blazers::whatAmI() const
{
    return blazer;
}
int Blazers::getApparel() const {
    return app_blazers;
}
identification Suit::whatAmI() const
{
    return suit;
}
int Suit::getApparel() const {
    return app_suit;
}
identification Tie::whatAmI() const
{
    return accessory;
}
int Tie::getApparel() const {
    return app_ties;
}
identification Cufflinks::whatAmI() const
{
    return accessory;
}
int Cufflinks::getApparel() const {
    return app_cufflinks;
}
identification Socks::whatAmI() const
{
    return socks;
}
int Socks::getApparel() const {
    return app_socks;
}
identification ActwearBottoms::whatAmI() const
{
    return bottom;
}
int ActwearBottoms::getApparel() const {
    return app_actwearbottoms;
}
identification Belts::whatAmI() const
{
    return accessory;
}
int Belts::getApparel() const {
    return app_belts;
}
identification CasualShirts::whatAmI() const
{
    return top;
}
int CasualShirts::getApparel() const {
    return app_casualshirts;
}
identification Chinos::whatAmI() const
{
    return bottom;
}
int Chinos::getApparel() const {
    return app_chinos;
}
identification DressPants::whatAmI() const
{
    return bottom;
}
int DressPants::getApparel() const {
    return app_dresspants;
}
identification Footwear::whatAmI() const
{
    return shoes;
}
int Footwear::getApparel() const {
    return app_footwears;
}
identification Jeans::whatAmI() const
{
    return bottom;
}
int Jeans::getApparel() const {
    return app_jeans;
}
identification PocketSquare::whatAmI() const
{
    return accessory;
}
int PocketSquare::getApparel() const {
    return app_pocketsquares;
}
identification Polos::whatAmI() const
{
    return top;
}
int Polos::getApparel() const {
    return app_polos;
}
identification Shorts::whatAmI() const
{
    return bottom;
}
int Shorts::getApparel() const {
    return app_shorts;
}
// Type Classification for derived items 

type FormalShirt::WhatType() const
{
    return formal;
}
type Accessory::WhatType() const
{
    return misc;
}
type Blazers::WhatType() const
{
    return semi_formal;
}
type Suit::WhatType() const
{
    return formal;
}
type Tie::WhatType() const
{
    return formal;
}
type Cufflinks::WhatType() const
{
    return formal;
}
type Socks::WhatType() const
{
    return misc;
}
type ActwearBottoms::WhatType() const
{
    return casual;
}

type Belts::WhatType() const
{
    return misc;
}

type CasualShirts::WhatType() const
{
    return semi_formal;
}

type Chinos::WhatType() const
{
    return casual;
}

type DressPants::WhatType() const
{
    return formal;
}

type Footwear::WhatType() const
{
    return misc;
}

type Jeans::WhatType() const
{
    return semi_formal;
}

type PocketSquare::WhatType() const
{
    return formal;
}

type Polos::WhatType() const
{
    return semi_formal;
}

type Shorts::WhatType() const
{
    return casual;
}

// Constructors for Derived Classes

// FormalShirt
FormalShirt::FormalShirt(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
     const std::string& fitValue, const std::string& stuffValue)
    : Top( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
    fit = fitValue;
    stuff = stuffValue;
}

// Accessory
Accessory::Accessory(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue)
    : Item( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
}

// Blazers
Blazers::Blazers(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
     const std::string& fitValue, const std::string& stuffValue)
    : Top( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
    fit = fitValue;
    stuff = stuffValue;
}

// Suit
Suit::Suit(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
     const std::string& fitValue, const std::string& stuffValue,
    const std::string& Name_typeValue)
    :  Bottom( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
    fit = fitValue;
    stuff = stuffValue;
    Name_type = Name_typeValue;
}

// Tie
Tie::Tie(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
     const std::string& Name_typeValue)
    : Accessory( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
    Name_type = Name_typeValue;
}

// Cufflinks
Cufflinks::Cufflinks(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
     const std::string& Name_typeValue)
    : Accessory( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
    Name_type = Name_typeValue;
}

// Socks
Socks::Socks(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
     const std::string& Name_typeValue, const std::string& stuffValue)
    : Accessory( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
    Name_type = Name_typeValue;
    stuff = stuffValue;
}

// top
Top::Top(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue) : Item( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
    //
}

// bottom
Bottom::Bottom(const std::string& idValue, const std::string& product_title, const std::string& priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue) : Item( idValue, product_title, priceValue, brandValue, colorValue, colorhexValue)
{
    //
}

// ActwearBottoms Class Constructor
ActwearBottoms::ActwearBottoms(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& name_type, const std::string& stuff)
    : Bottom(id, product_title, price, brand, color, colorhex), name_type(name_type), stuff(stuff) {}

// Belts Class Constructor
Belts::Belts(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& name_type)
    : Accessory(id, product_title, price, brand, color, colorhex), name_type(name_type) {}

// CasualShirts Class Constructor
CasualShirts::CasualShirts(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& name_type, const std::string& stuff)
    : Top(id, product_title, price, brand, color, colorhex), name_type(name_type), stuff(stuff) {}

// Chinos Class Constructor
Chinos::Chinos(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& name_type, const std::string& stuff)
    : Bottom(id, product_title, price, brand, color, colorhex), name_type(name_type), stuff(stuff) {}

// DressPants Class Constructor
DressPants::DressPants(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& name_type, const std::string& stuff, const std::string& fit)
    : Bottom(id, product_title, price, brand, color, colorhex), name_type(name_type), stuff(stuff), fit(fit) {}

// Footwear Class Constructor
Footwear::Footwear(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& name_type)
    : Accessory(id, product_title, price, brand, color, colorhex), name_type(name_type) {}

// Jeans Class Constructor
Jeans::Jeans(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& name_type)
    : Bottom(id, product_title, price, brand, color, colorhex), name_type(name_type) {}

// PocketSquare Class Constructor
PocketSquare::PocketSquare(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex)
    : Accessory(id, product_title, price, brand, color, colorhex) {}

// Polos Class Constructor
Polos::Polos(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& stuff, const std::string& name_type)
    : Top(id, product_title, price, brand, color, colorhex), stuff(stuff), name_type(name_type) {}

// Shorts Class Constructor
Shorts::Shorts(const std::string& id, const std::string& product_title, const std::string& price, const std::string& brand, const std::string& color, int colorhex, const std::string& stuff, const std::string& name_type)
    : Bottom(id, product_title, price, brand, color, colorhex), stuff(stuff), name_type(name_type) {}
