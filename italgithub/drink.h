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
    ///Visszaadja az Ital nev�t
    ///@return std::string az Ital nev�vel
    std::string getname() const { return Dname; }

    ///Visszaadja az Ital i-edik Alapanyag�t
    ///@param i - hanyadik Alapanyag
    ///@return std::string az Alapanyag nev�vel
    Liquid* getIng(size_t i) const { return Ings[i]; }

    double getIngvol(size_t i) const { return Ings[i]->getVol(); }

    ///Visszaadja az Ital �rtartalm�t, dl a m�rt�kegys�g
    ///@return az Ital �rtartalma
    double getvol() const { return volume; }

    ///Visszaadja az Ital Alapanyagainak  sz�m�t
    ///@return Alapanyagok sz�ma
    size_t getingNum() const { return ingNum; }

    ///Teljes konstruktor
    ///@param str - az Ital nev�t tartalmaz� std::string
    ///@param ing - heterog�n kollekci� Alapanyagokkal
    ///@param vol - az Ital �rtartalma
    Drink(std::string str, const std::vector<Liquid*>& ing, size_t ingNum, double vol) : Dname(str), Ings(ing), ingNum(ing.size()), volume(vol) {};

    void writeToFile(const Drink& d);

    ///Ki�rja az Ital Alapanyagait
    void showIngs();

    Drink& operator+(const Drink& rhs);

    Drink& operator=(const Drink& rhs);

    ~Drink();
};
///Ki�r egy Italt az ostream-re
std::ostream& operator<<(std::ostream& os, const Drink& d);

#endif // DRINK_H
