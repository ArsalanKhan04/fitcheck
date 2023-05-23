#include "Search.h"
#include <iostream>
#include <wx\wx.h>

Outfit::Outfit() {
	outfit_suit = nullptr;
	outfit_bottom = nullptr;
	outfit_top = nullptr;
	outfit_tie = nullptr;
	outfit_belts = nullptr;
	outfit_cufflinks = nullptr;
	outfit_blazers = nullptr;
	outfit_socks = nullptr;
	outfit_footwears = nullptr;
	outfit_pocketsquare = nullptr;
    outfittype = STFS;
}

void Outfit::setSuit(Item* newSuit) {
    outfit_suit = newSuit;
}

Item* Outfit::getSuit() const {
    return outfit_suit;
}

void Outfit::setBottom(Item* newBottom) {
    outfit_bottom = newBottom;
}

Item* Outfit::getBottom() const {
    return outfit_bottom;
}

void Outfit::setTop(Item* newTop) {
    outfit_top = newTop;
}

Item* Outfit::getTop() const {
    return outfit_top;
}

void Outfit::setTie(Item* newTie) {
    outfit_tie = newTie;
}

Item* Outfit::getTie() const {
    return outfit_tie;
}

void Outfit::setBelts(Item* newBelts) {
    outfit_belts = newBelts;
}

Item* Outfit::getBelts() const {
    return outfit_belts;
}

void Outfit::setCufflinks(Item* newCufflinks) {
    outfit_cufflinks = newCufflinks;
}

Item* Outfit::getCufflinks() const {
    return outfit_cufflinks;
}

void Outfit::setBlazers(Item* newBlazers) {
    if (outfit_suit != nullptr) {
        throw std::invalid_argument("This outfit can not add a blazer");
    }
    outfit_blazers = newBlazers;
}

Item* Outfit::getBlazers() const {
    return outfit_blazers;
}

void Outfit::setSocks(Item* newSocks) {
    outfit_socks = newSocks;
}

Item* Outfit::getSocks() const {
    return outfit_socks;
}

void Outfit::setFootwears(Item* newFootwears) {
    outfit_footwears = newFootwears;
}

Item* Outfit::getFootwears() const {
    return outfit_footwears;
}

void Outfit::setPocketSquare(Item* newPocketSquare) {
    outfit_pocketsquare = newPocketSquare;
}

Item* Outfit::getPocketSquare() const {
    return outfit_pocketsquare;
}


void Outfit::setWeight(Weight weight) {
    this->weight = weight;
}
Weight Outfit::getWeight() const {
    return weight;
}


bool Outfit::haveSuit() const {
    return !(outfit_suit == nullptr);
}
bool Outfit::haveBottom() const {
    return !(outfit_bottom == nullptr);
}
bool Outfit::haveTop() const {
    return !(outfit_top == nullptr);
}
bool Outfit::haveTie() const {
    return !(outfit_tie == nullptr);
}
bool Outfit::haveBelts() const {
    return !(outfit_belts == nullptr);
}
bool Outfit::haveCufflinks() const {
    return !(outfit_cufflinks == nullptr);
}
bool Outfit::haveBlazers() const {
    return !(outfit_blazers == nullptr);
}
bool Outfit::haveSocks() const {
    return !(outfit_socks == nullptr);
}
bool Outfit::haveFootwears() const {
    return !(outfit_footwears == nullptr);
}
bool Outfit::havePocketSquare() const {
    return !(outfit_pocketsquare == nullptr);
}

void Outfit::addItem(Item* item) {
    
    if (item->whatAmI() == top) {
        setTop(item);
    }
    else if (item->whatAmI() == bottom) {
        setBottom(item);
    }
    else if (item->getApparel() == app_suit) {
        setSuit(item);
    }
    else if (item->whatAmI() == blazer) {
        setBlazers(item);
    }
    else if (item->whatAmI() == shoes) {
        setFootwears(item);
    }
    else if (item->whatAmI() == socks) {
        setSocks(item);
    }
    else if (item->getApparel() == app_belts) {
        setBelts(item);
    }
    else if (item->getApparel() == app_cufflinks) {
        setCufflinks(item);
    }
    else if (item->getApparel() == app_ties) {
        setTie(item);
    }
    else if (item->getApparel() == app_pocketsquares) {
        setPocketSquare(item);
    }

}


bool compareContrast(Outfit* a, Outfit* b) {
    return a->getWeight().getContrast() < b->getWeight().getContrast();
}

bool compareMatch(Outfit* a, Outfit* b) {
    return a->getWeight().getMatching() < b->getWeight().getMatching();
}




Search::Search() {
    alldata = new Data;
    alldata->load();
}

std::vector <Outfit*> Search::completeOutfit(int formal_type, int compare_type) {

    std::vector <Outfit*> outfitList;
    Outfit* eachoutfit;
    vector <Item*> suits;
    vector <Item*> bottoms;
    vector <Item*> tops;
    vector <Item*> blazers;
    if (haveTop()) {
        tops.push_back(getTop());
    }
    else {
        for (Item* eachTop: alldata->getTops()) {
            tops.push_back(eachTop);
        }
    }

    if (formal_type == formal) {

        if (haveSuit()) {
            suits.push_back(getSuit());
        }
        else {
            for (Item* eachSuit : alldata->getSuits()) {
                suits.push_back(eachSuit);
            }
        }
        for (Item* eachSuit : suits) {
            for (Item* eachTop : tops) {
                if (eachTop->WhatType() == formal) {
                    eachoutfit = new Outfit();
                    eachoutfit->setTop(eachTop);
                    eachoutfit->setSuit(eachSuit);
                    eachoutfit->setWeight(Weight(*eachTop, *eachSuit));
                    outfitList.push_back(eachoutfit);
                }
            }
        }
    }
    else if (formal_type == semi_formal) {
        if (haveBlazers()) {
            blazers.push_back(getBlazers());
        }
        else {
            for (Item* eachBlazer : alldata->getBlazers()) {
                blazers.push_back(eachBlazer);
            }
        }
        if (haveBottom()) {
            bottoms.push_back(getBottom());
        }
        else {
            for (Item* eachbottom : alldata->getBottoms()) {
                bottoms.push_back(eachbottom);
            }
        }
        for (Item* eachBlazer : blazers) {
            for (Item* eachTop : tops) {
                for (Item* eachBottom : bottoms) {
                    if (eachTop->WhatType() == formal) {
                        if (eachBottom->WhatType() == semi_formal) {
                            eachoutfit = new Outfit();
                            eachoutfit->setTop(eachTop);
                            eachoutfit->setBlazers(eachBlazer);
                            eachoutfit->setBottom(eachBottom);

                            eachoutfit->setWeight((Weight(*eachTop, *eachBlazer) + Weight(*eachTop, *eachBottom) + Weight(*eachBottom, *eachBlazer)) / 3);
                            outfitList.push_back(eachoutfit);
                        }
                    }
                }
            }
        }

    }
    else if (formal_type == casual) {
        if (haveBottom()) {

            bottoms.push_back(getBottom());
        }
        else {
            for (Item* eachbottom : alldata->getBottoms()) {
                bottoms.push_back(eachbottom);
            }
        }

        for (Item* eachTop : tops) {
            for (Item* eachBottom : bottoms) {
                if (eachTop->WhatType() == formal) {
                    if (eachBottom->WhatType() == casual) {
                        eachoutfit = new Outfit();
                        eachoutfit->setTop(eachTop);
                        eachoutfit->setBottom(eachBottom);
                        outfitList.push_back(eachoutfit);

                        eachoutfit->setWeight(Weight(*eachTop, *eachBottom));
                    }
                }
            }
        }

    }
    /*
    for (Outfit* x : outfitList) {
        std::string message = x->getSuit()->getProductTitle();
        message += " ";
        message += x->getTop()->getProductTitle();
        wxString wxMessage = wxString::FromUTF8(message.c_str());
        wxLogMessage(wxMessage);
    }
    */
    if (compare_type == 0) {
        std::sort(outfitList.begin(), outfitList.end(), compareMatch);
    }
    else {
        std::sort(outfitList.begin(), outfitList.end(), compareContrast);
    }
    return outfitList;
    /*
    for (Item* eachSuit : alldata->getSuits()){
        for (Item* eachTop : alldata->getTops()) {
            for (Item* eachtie: alldata->getTies()){
                for (Item* eachbelt : alldata->getBelts()) {
                    for (Item* eachcufflink : alldata->getCufflinks()) {
                        for (Item* eachpocketsquare : alldata->getPocketsquares()) {
                            newsuit = haveSuit() ? getSuit() : eachSuit;
                            newtop = haveTop() ? getTop() : eachTop;
                            newtie = haveTie() ? getTie() : eachtie;
                            newbelt = haveBelts() ? getBelts() : eachbelt;
                            newcufflinks = haveCufflinks() ? getCufflinks() : eachcufflink;
                            newpocketsquare = havePocketSquare() ? getPocketSquare() : eachpocketsquare;
                            eachoutfit = new Outfit;
                            eachoutfit->setSuit(newsuit);
                            eachoutfit->setTop(newtop);
                            eachoutfit->setTie(newtie);
                            eachoutfit->setBelts(newbelt);
                            eachoutfit->setCufflinks(newcufflinks);
                            eachoutfit->setPocketSquare(newpocketsquare);
                            outfitList.push_back(eachoutfit);
                        }
                    }
                }
            }
        }
    }
    */
}
/*
bool Search::compareContrast(Outfit* a, Outfit* b) {
    return a->calculateweight()->getContrast() < b->calculateweight()->getContrast();
}

bool Search::compareMatch(Outfit* a, Outfit* b) {
    return a->calculateweight()->getMatching() < b->calculateweight()->getMatching();
}


std::vector <Outfit*> Search::getOutfitList() const {
    return outfitList;
}

std::vector <Outfit*> Search::getOutfitListContrast() const {
    vector <Outfit*> newlist(outfitList);
    std::sort(newlist.begin(), newlist.end(), compareContrast);
    return newlist;
}

std::vector <Outfit*> Search::getOutfitListMatch() const {
    vector <Outfit*> newlist(outfitList);
    std::sort(newlist.begin(), newlist.end(), compareMatch);
    return newlist;
}

*/

