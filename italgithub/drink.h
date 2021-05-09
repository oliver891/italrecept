#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <fstream>
#include <vector>


#include "liquid.h"

class Drink {
    std::string Dname;
    std::vector<Liquid*> Ings;
    size_t ingNum;
    double volume;
public:
    ///Visszaadja az Ital nevét
    ///@return std::string az Ital nevével
    std::string getname() const { return Dname; }

    ///Visszaadja az Ital i-edik Alapanyagát
    ///@param i - hanyadik Alapanyag
    ///@return std::string az Alapanyag nevével
    Liquid* getIng(size_t i) const { return Ings[i]; }

    double getIngvol(size_t i) const { return Ings[i]->getVol(); }

    ///Visszaadja az Ital ûrtartalmát, dl a mértékegység
    ///@return az Ital ûrtartalma
    double getvol() const { return volume; }

    ///Visszaadja az Ital Alapanyagainak  számát
    ///@return Alapanyagok száma
    size_t getingNum() const { return ingNum; }

    ///Teljes konstruktor
    ///@param str - az Ital nevét tartalmazó std::string
    ///@param ing - heterogén kollekció Alapanyagokkal
    ///@param vol - az Ital ûrtartalma
    Drink(std::string str, const std::vector<Liquid*>& ing, size_t ingNum, double vol) : Dname(str), Ings(ing), ingNum(ing.size()), volume(vol) {};

    void writeToFile(const Drink& d);

    ///Kiírja az Ital Alapanyagait
    void showIngs();

    Drink& operator+(const Drink& rhs);

    Drink& operator=(const Drink& rhs);

    ~Drink();
};
///Kiír egy Italt az ostream-re
std::ostream& operator<<(std::ostream& os, const Drink& d);

#endif // DRINK_H
