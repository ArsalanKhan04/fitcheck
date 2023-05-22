#include "Weight.h"
#include <cmath>



Weight::Weight() {
    formal_weight = 0;
    casual_weight = 0;
    Semi_formal_weight = 0;
    misc_weight = 0;
    matching = 0;
    contrast = 0;
}

Weight:: Weight(const Weight& other) {
    formal_weight = other.formal_weight;
    casual_weight = other.casual_weight;
    Semi_formal_weight = other.Semi_formal_weight;
    misc_weight = other.misc_weight;
    matching = other.matching;
    contrast = other.contrast;
}

Weight::Weight(Item& I1, Item& I2)
{
    type T1, T2;
    T1 = I1.WhatType();
    T2 = I2.WhatType();

    if ((T1 == type::formal) && (T2 == type::formal)) {
        formal_weight = 10;
        casual_weight = 200;
        Semi_formal_weight = 200;
        misc_weight = 200;
    }
    else if ((T1 == type::formal) && (T2 == type::casual)) {
        formal_weight = 50;
        casual_weight = 200;
        Semi_formal_weight = 10;
        misc_weight = 200;
    }
    else if ((T1 == type::formal) && (T2 == type::semi_formal)) {
        formal_weight = 20;
        casual_weight = 200;
        Semi_formal_weight = 10;
        misc_weight = 200;
    }
    else if ((T1 == type::formal) && (T2 == type::misc)) {
        formal_weight = 20;
        casual_weight = 200;
        Semi_formal_weight = 200;
        misc_weight = 50;
    }
    else if ((T1 == type::casual) && (T2 == type::casual)) {
        formal_weight = 200;
        casual_weight = 10;
        Semi_formal_weight = 200;
        misc_weight = 200;
    }
    else if ((T1 == type::casual) && (T2 == type::semi_formal)) {
        formal_weight = 200;
        casual_weight = 10;
        Semi_formal_weight = 50;
        misc_weight = 200;
    }
    else if ((T1 == type::casual) && (T2 == type::misc)) {
        formal_weight = 200;
        casual_weight = 20;
        Semi_formal_weight = 200;
        misc_weight = 30;
    }
    else if ((T1 == type::semi_formal) && (T2 == type::semi_formal)) {
        formal_weight = 50;
        casual_weight = 200;
        Semi_formal_weight = 10;
        misc_weight = 200;
    }
    else if ((T1 == type::semi_formal) && (T2 == type::misc)) {
        formal_weight = 200;
        casual_weight = 200;
        Semi_formal_weight = 10;
        misc_weight = 50;
    }
    else {
        formal_weight = 200;
        casual_weight = 200;
        Semi_formal_weight = 200;
        misc_weight = 10;
    }

    matching = (double)log10(sqrt((pow(I1 - I2, 2)) + 100) * 10000000000000);
    contrast = log10(((double)1 / matching) + 100);

}

Weight Weight::operator+(const Weight& other) const {
    Weight newWeight;
    newWeight.casual_weight = casual_weight + other.casual_weight;
    newWeight.formal_weight = formal_weight + other.formal_weight;
    newWeight.Semi_formal_weight = Semi_formal_weight + other.Semi_formal_weight;
    newWeight.misc_weight = misc_weight + other.misc_weight;
    newWeight.matching = matching + other.matching;
    newWeight.contrast = contrast + other.contrast;
    return newWeight;
}
Weight Weight::operator/(int num) const {
    Weight newWeight;
    newWeight.casual_weight = casual_weight / num;
    newWeight.formal_weight = formal_weight /num ;
    newWeight.Semi_formal_weight = Semi_formal_weight / num;
    newWeight.misc_weight = misc_weight / num;
    newWeight.matching = matching / num;
    newWeight.contrast = contrast / num;
    return newWeight;
}
int Weight::getFormalWeight() const {
    return formal_weight;
}

int Weight::getCasualWeight() const {
    return casual_weight;
}

int Weight::getSemiFormalWeight() const {
    return Semi_formal_weight;
}

int Weight::getMiscWeight() const {
    return misc_weight;
}

int Weight::getContrast() const {
    return contrast;
}

int Weight::getMatching() const {
    return matching;
}

