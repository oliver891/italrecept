#ifndef LIQUID_H
#define LIQUID_H

#include <iostream>
#include <string>
/**
 * Alapanyag oszt�ly
 * Lname-ben van elt�rolva az adott Alapanyag neve
 */
class Liquid {
    std::string Lname;
    double volume;
public:
    ///0 param�teres ctor
    Liquid() {};

    ///1 param�teres ctor egy n�vvel
    Liquid(std::string name, double vol) : Lname(name), volume(vol) {};

    std::string getName() const { return Lname;}

    double getVol() const { return volume;}

    virtual void print() const;
    virtual std::ostream& printFile(std::ostream& os) const;

    virtual ~Liquid() { delete this; }
};
std::ostream& operator<<(std::ostream& os, const Liquid& L);

/**
 * Alkohol oszt�ly, az Alapanyagb�l sz�rmaztatva
 * alcvolban az adott Alkohol alkoholsz�zal�ka van elt�rolva
 */
class Alcohol : public Liquid {
    double alcvol;
public:
    ///0 param�teres ctor
    Alcohol() : Liquid() {};

    ///2 param�teres ctor egy n�vvel �s egy alkoholsz�zal�kkal
    Alcohol(std::string name, double vol, double alcvolume) : Liquid(name, vol), alcvol(alcvolume) {};

    ///Visszaadja az adott Alkohol alkoholsz�zal�k�t
    ///@return az Alkohol alkoholsz�zal�ka
    double getAlcvol() const { return alcvol;}

    void print() const;
    std::ostream& printFile(std::ostream& os) const;

    ~Alcohol() { delete this; }
};
std::ostream& operator<<(std::ostream& os, const Alcohol& A);

#endif // LIQUID_H
