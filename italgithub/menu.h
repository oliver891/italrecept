#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "drink.h"
#include "liquid.h"

class Menu {
public:
    Menu() { showMenu(); }

    /// Ki�rja a kezd�men�t
    void showMenu();

    ///Megh�vja a men�t vez�rl� switch szerkezetet
    void choose();

    ///Az 1. men�pont almen�jeit �rja ki
    void showMenu1();
        ///Opci� az �sszes Ital ki�r�s�ra
        void showDrinks();
        ///Opci� egy Ital hozz�ad�s�ra
        void addDrink();
        ///Opci� egy Ital t�rl�s�re
        void deleteDrink();
    ///A 2. men�pont almen�jeit �rja ki
    void showMenu2();
        ///Kilist�zza az �sszes hozz�val�t
        void showIngs();
        ///Opci� egy �j hozz�val� hozz�ad�s�ra
        void addIngr();

    void addDmenu() const;

    ///Visszaadja egy std::stringben a tabok sz�m�t
    ///@param str - Bemeneti std::string
    size_t numofTabs(const std::string& str) const;

    ///Feldarabol egy std::stringet szavakra �s egy heterog�n kollekci�k�nt adja vissza
    ///@param str - Bemeneti std::string
    std::vector<std::string> splitbyword(const std::string& str) const;

    ///Italt k�sz�t egy Alapanyagokat tartalmaz� heterog�n kollekci�b�l
    ///@param vec - bemeneti h.k.
    Drink makeD(const std::vector<std::string>& vec);

    ///Men� destruktora, elk�sz�n a felhaszn�l�t�l
    ~Menu() { std::cout << "Viszlat!" << std::endl;}
};
#endif // MENU_H
