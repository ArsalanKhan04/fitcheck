#include "item.h"
using namespace std;
Item::Item(const std::string& id, const std::string& product_title, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink) {
    this->id = id;
    this->product_title = product_title;
    this->price = price;
    this->brand = brand;
    this->color = color;
    this->colorhex = colorhex;
    this->imageLink = imageLink;
}

std::string Item::getId() const {
    return id;
}

std::string Item::getProductTitle() const {
    return product_title;
}

int Item::getPrice() const {
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

// Identification for derived items

identification FormalShirt::whatAmI() const
{
    return top;
}
identification Accessory::whatAmI() const
{
    return accessory;
}
identification Blazers::whatAmI() const
{
    return blazer;
}
identification Suit::whatAmI() const
{
    return suit;
}
identification Tie::whatAmI() const
{
    return accessory;
}
identification Cufflinks::whatAmI() const
{
    return accessory;
}
identification Socks::whatAmI() const
{
    return socks;
}
identification ActwearBottoms::whatAmI() const
{
    return bottom;
}

identification Belts::whatAmI() const
{
    return accessory;
}

identification CasualShirts::whatAmI() const
{
    return top;
}

identification Chinos::whatAmI() const
{
    return bottom;
}

identification DressPants::whatAmI() const
{
    return bottom;
}

identification Footwear::whatAmI() const
{
    return shoes;
}

identification Jeans::whatAmI() const
{
    return bottom;
}

identification PocketSquare::whatAmI() const
{
    return accessory;
}

identification Polos::whatAmI() const
{
    return top;
}

identification Shorts::whatAmI() const
{
    return bottom;
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
    return casual;
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
FormalShirt::FormalShirt(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue, const std::string& fitValue, const std::string& stuffValue)
    : Top(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
    fit = fitValue;
    stuff = stuffValue;
}

// Accessory
Accessory::Accessory(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue)
    : Item(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
}

// Blazers
Blazers::Blazers(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue, const std::string& fitValue, const std::string& stuffValue)
    : Top(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
    fit = fitValue;
    stuff = stuffValue;
}

// Suit
Suit::Suit(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue, const std::string& fitValue, const std::string& stuffValue,
    const std::string& Name_typeValue)
    : Top(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue), Bottom(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
    fit = fitValue;
    stuff = stuffValue;
    Name_type = Name_typeValue;
}

// Tie
Tie::Tie(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue, const std::string& Name_typeValue)
    : Accessory(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
    Name_type = Name_typeValue;
}

// Cufflinks
Cufflinks::Cufflinks(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue, const std::string& Name_typeValue)
    : Accessory(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
    Name_type = Name_typeValue;
}

// Socks
Socks::Socks(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue, const std::string& Name_typeValue, const std::string& stuffValue)
    : Accessory(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
    Name_type = Name_typeValue;
    stuff = stuffValue;
}

// top
Top::Top(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue) : Item(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
    //
}

// bottom
Bottom::Bottom(const std::string& categoryValue, const std::string& idValue, int priceValue,
    const std::string& brandValue, const std::string& colorValue, int colorhexValue,
    const std::string& imageLinkValue) : Item(categoryValue, idValue, priceValue, brandValue, colorValue, colorhexValue, imageLinkValue)
{
    //
}

// ActwearBottoms Class Constructor
ActwearBottoms::ActwearBottoms(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink, const std::string& name_type, const std::string& stuff)
    : Bottom(category, id, price, brand, color, colorhex, imageLink), name_type(name_type), stuff(stuff) {}

// Belts Class Constructor
Belts::Belts(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink, const std::string& name_type)
    : Accessory(category, id, price, brand, color, colorhex, imageLink), name_type(name_type) {}

// CasualShirts Class Constructor
CasualShirts::CasualShirts(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink, const std::string& name_type, const std::string& stuff)
    : Top(category, id, price, brand, color, colorhex, imageLink), name_type(name_type), stuff(stuff) {}

// Chinos Class Constructor
Chinos::Chinos(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink, const std::string& name_type, const std::string& stuff)
    : Bottom(category, id, price, brand, color, colorhex, imageLink), name_type(name_type), stuff(stuff) {}

// DressPants Class Constructor
DressPants::DressPants(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink, const std::string& name_type, const std::string& stuff, const std::string& fit)
    : Bottom(category, id, price, brand, color, colorhex, imageLink), name_type(name_type), stuff(stuff), fit(fit) {}

// Footwear Class Constructor
Footwear::Footwear(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink, const std::string& name_type)
    : Accessory(category, id, price, brand, color, colorhex, imageLink), name_type(name_type) {}

// Jeans Class Constructor
Jeans::Jeans(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink, const std::string& name_type)
    : Bottom(category, id, price, brand, color, colorhex, imageLink), name_type(name_type) {}

// PocketSquare Class Constructor
PocketSquare::PocketSquare(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink)
    : Accessory(category, id, price, brand, color, colorhex, imageLink) {}

// Polos Class Constructor
Polos::Polos(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex,
    const std::string& imageLink, const std::string& stuff, const std::string& name_type)
    : Top(category, id, price, brand, color, colorhex, imageLink), stuff(stuff), name_type(name_type) {}

// Shorts Class Constructor
Shorts::Shorts(const std::string& category, const std::string& id, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink, const std::string& stuff, const std::string& name_type)
    : Bottom(category, id, price, brand, color, colorhex, imageLink), stuff(stuff), name_type(name_type) {}
