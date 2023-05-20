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