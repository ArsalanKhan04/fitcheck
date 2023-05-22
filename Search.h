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
	Suit* outfit_suit;
	Bottom* outfit_bottom;
	Top* outfit_top;
	Tie* outfit_tie;
	Belts* outfit_belts;
	Cufflinks* outfit_cufflinks;
	Blazers* outfit_blazers;
	Socks* outfit_socks;
	Footwear* outfit_footwears;
	PocketSquare* outfit_pocketsquare;
    int outfittype;
public:
	Outfit();
    void setSuit(Suit* newSuit);
    Suit* getSuit() const;
    void setBottom(Bottom* newBottom);
    Bottom* getBottom() const;
    void setTop(Top* newTop);
    Top* getTop() const;
    void setTie(Tie* newTie);
    Tie* getTie() const;
    void setBelts(Belts* newBelts);
    Belts* getBelts() const;
    void setCufflinks(Cufflinks* newCufflinks);
    Cufflinks* getCufflinks() const;
    void setBlazers(Blazers* newBlazers);
    Blazers* getBlazers() const;
    void setSocks(Socks* newSocks);
    Socks* getSocks() const;
    void setFootwears(Footwear* newFootwears);
    Footwear* getFootwears() const;
    void setPocketSquare(PocketSquare* newPocketSquare);
    PocketSquare* getPocketSquare() const;
    Weight* calculateweight();

    template <class T>
    void addItem(const T*) const;


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
    std::vector <Outfit*> outfitList;
    Data* alldata;
    bool compareContrast(Outfit*, Outfit*);
    bool compareMatch(Outfit*, Outfit*);
public:
    void completeOutfit(int formal_type);
    std::vector <Outfit*> getOutfitList() const;
    // std::vector <Outfit*> getOutfitListContrast() const;
    // std::vector <Outfit*> getOutfitListMatch() const;
};

