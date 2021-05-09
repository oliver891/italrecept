#ifndef MENU_H
#define MENU_H

#include <iostream>

#include "drink.h"
#include "liquid.h"

class Menu {
public:
    Menu() { showMenu(); }

    /// Kiírja a kezdõmenüt
    void showMenu();

    ///Meghívja a menüt vezérlõ switch szerkezetet
    void choose();

    ///Az 1. menüpont almenüjeit írja ki
    void showMenu1();
        ///Opció az összes Ital kiírására
        void showDrinks();
        ///Opció egy Ital hozzáadására
        void addDrink();
        ///Opció egy Ital törlésére
        void deleteDrink();
    ///A 2. menüpont almenüjeit írja ki
    void showMenu2();
        ///Kilistázza az összes hozzávalót
        void showIngs();
        ///Opció egy új hozzávaló hozzáadására
        void addIngr();

    void addDmenu() const;

    ///Visszaadja egy std::stringben a tabok számát
    ///@param str - Bemeneti std::string
    size_t numofTabs(const std::string& str) const;

    ///Feldarabol egy std::stringet szavakra és egy heterogén kollekcióként adja vissza
    ///@param str - Bemeneti std::string
    std::vector<std::string> splitbyword(const std::string& str) const;

    ///Italt készít egy Alapanyagokat tartalmazó heterogén kollekcióból
    ///@param vec - bemeneti h.k.
    Drink makeD(const std::vector<std::string>& vec);

    ///Menü destruktora, elköszön a felhasználótól
    ~Menu() { std::cout << "Viszlat!" << std::endl;}
};
#endif // MENU_H
