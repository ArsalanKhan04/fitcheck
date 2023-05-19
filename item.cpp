#include "item.h"

Item::Item (const std::string& id, const std::string& product_title, int price, const std::string& brand, const std::string& color, int colorhex, const std::string& imageLink) {
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