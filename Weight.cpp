#include "Weight.h"
#include <cmath>





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