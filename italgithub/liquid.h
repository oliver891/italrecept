#ifndef LIQUID_H
#define LIQUID_H

#include <iostream>
#include <string>
/**
 * Alapanyag osztály
 * Lname-ben van eltárolva az adott Alapanyag neve
 */
class Liquid {
    std::string Lname;
    double volume;
public:
    ///0 paraméteres ctor
    Liquid() {};

    ///1 paraméteres ctor egy névvel
    Liquid(std::string name, double vol) : Lname(name), volume(vol) {};

    std::string getName() const { return Lname;}

    double getVol() const { return volume;}

    virtual void print() const;
    virtual std::ostream& printFile(std::ostream& os) const;

    virtual ~Liquid() { delete this; }
};
std::ostream& operator<<(std::ostream& os, const Liquid& L);

/**
 * Alkohol osztály, az Alapanyagból származtatva
 * alcvolban az adott Alkohol alkoholszázaléka van eltárolva
 */
class Alcohol : public Liquid {
    double alcvol;
public:
    ///0 paraméteres ctor
    Alcohol() : Liquid() {};

    ///2 paraméteres ctor egy névvel és egy alkoholszázalékkal
    Alcohol(std::string name, double vol, double alcvolume) : Liquid(name, vol), alcvol(alcvolume) {};

    ///Visszaadja az adott Alkohol alkoholszázalékát
    ///@return az Alkohol alkoholszázaléka
    double getAlcvol() const { return alcvol;}

    void print() const;
    std::ostream& printFile(std::ostream& os) const;

    ~Alcohol() { delete this; }
};
std::ostream& operator<<(std::ostream& os, const Alcohol& A);

#endif // LIQUID_H
