#pragma once
#include "item.h"
#include "Weight.h"
#include "Data.h"
#include <iostream>

enum outfittype {
    STFS = 691, // Suit - Top - Footwear - Socks
    BTBFS = 692, // Blazer - Top - Bottom - Footwear - Socks
    TBFS = 693 // Top - Bottom - Footwear - Socks

};

class Outfit
{
private:
	Item* outfit_suit;
	Item* outfit_bottom;
	Item* outfit_top;
	Item* outfit_tie;
	Item* outfit_belts;
	Item* outfit_cufflinks;
	Item* outfit_blazers;
	Item* outfit_socks;
	Item* outfit_footwears;
	Item* outfit_pocketsquare;
    int outfittype;
public:
	Outfit();
    void setSuit(Item* newSuit);
    Item* getSuit() const;
    void setBottom(Item* newBottom);
    Item* getBottom() const;
    void setTop(Item* newTop);
    Item* getTop() const;
    void setTie(Item* newTie);
    Item* getTie() const;
    void setBelts(Item* newBelts);
    Item* getBelts() const;
    void setCufflinks(Item* newCufflinks);
    Item* getCufflinks() const;
    void setBlazers(Item* newBlazers);
    Item* getBlazers() const;
    void setSocks(Item* newSocks);
    Item* getSocks() const;
    void setFootwears(Item* newFootwears);
    Item* getFootwears() const;
    void setPocketSquare(Item* newPocketSquare);
    Item* getPocketSquare() const;
    Weight* calculateweight();

    void addItem(Item*);


    bool haveSuit() const;
    bool haveBottom() const;
    bool haveTop() const;
    bool haveTie() const;
    bool haveBelts() const;
    bool haveCufflinks() const;
    bool haveBlazers() const;
    bool haveSocks() const;
    bool haveFootwears() const;
    bool havePocketSquare() const;
};


class Search: public Outfit
{
    Data* alldata;
    //bool compareContrast(Outfit*, Outfit*);
    // bool compareMatch(Outfit*, Outfit*);
public:
    std::vector <Outfit*> completeOutfit(int formal_type);
    Search();
    // std::vector <Outfit*> getOutfitList() const;
    // std::vector <Outfit*> getOutfitListContrast() const;
    // std::vector <Outfit*> getOutfitListMatch() const;
};

