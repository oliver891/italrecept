#include "menu.h"
#include <string>

#include <iostream>
#include <fstream>
#include <vector>

void Menu::showMenu() {
    std::cout   << "Udvozollek az italrecept programban!" << std::endl
                << "Valassz az alabbi menupontok kozul:" << std::endl
                << "1. Receptek" << std::endl
                << "2. Alapanyagok" << std::endl
                << "0. Kilepes" << std::endl;
}

void Menu::showMenu1() {
    std::cout   << "1. Receptek kilistazasa" << std::endl
                << "2. Uj recept hozzaadasa" << std::endl
                << "3. Recept torlese"       << std::endl
                << "0. Vissza a fomenube"    << std::endl;
}

void  Menu::showMenu2() {
    std::cout   << "1. Alapanyagok kilistazasa" << std::endl
                << "2. Uj alapanyag hozzaadasa" << std::endl
                << "0. Vissza a fomenube"       << std::endl;
}

size_t Menu::numofTabs(const std::string& str) const {
    size_t k = 0;
    for(size_t i = 0; i < str.size(); i++) {
        if(str[i] == '\t')
            k++;
    }
    return k;
}

std::vector<std::string> Menu::splitbyword(const std::string& str) const {
    std::vector<std::string> splitted;
    std::string temp;
    size_t k = 0;
    size_t l = 0;
    for(size_t i = 0; i < str.length()+1; i++){
        char c = str[i];

        if (c == '\t') {
            splitted.push_back(temp);
            temp.clear();
            continue;
        }
        if (c == '\n') {
                splitted.push_back(temp);
                temp.clear();
                break;
        }
        temp.push_back(c);
    }
    splitted.push_back(temp);
 /*   for(size_t i = 0; i < splitted.size(); i ++)
        std::cout << splitted[i] << std::endl; */
    return splitted;
}



Drink Menu::makeD(const std::vector<std::string>& vec) {
    std::string name = vec[0];
    std::vector<Liquid*> ings;
    size_t k = 0;
    double volume = 0;
    double voltmp = 0;
    double alcvoltmp = 0;
    for(size_t i = 1; i < vec.size(); i++) {
        if(i % 2 == 1) {
            size_t fo = vec[i].find(',');
            if(fo != std::string::npos) {
                volume += voltmp = std::stod(vec[i+1]);
                std::string tmp = vec[i].substr(0, fo);
                alcvoltmp = std::stod(vec[i].substr(fo+1, vec[i].length()));
          //      Alcohol tmpA = new Alcohol(tmp, voltmp, alcvoltmp);
                ings.push_back(new Alcohol(tmp, voltmp, alcvoltmp));
            }
            else {
                volume += voltmp = std::stod(vec[i+1]);
 //               Liquid tmpL = new Liquid(vec[i], voltmp);
                ings.push_back(new Liquid(vec[i], voltmp));
            }
            k++;
        }
    }
    Drink d(name, ings, k, volume);

    return d;
}

void Menu::showDrinks() {
    std::ifstream file("Italok.txt");
    std::string str;
    std::vector<Drink*> drinks;

    while (std::getline(file, str) ) {

        std::vector<std::string> spl = splitbyword(str);
        drinks.push_back(new Drink(makeD(spl)));
    }
    for(size_t i = 0; i < drinks.size(); ++i)
        std::cout << *drinks[i] << std::endl;
}

void Menu::addDmenu() const {
    std::cout << "1. Alkoholos a hozzavalo?" << std::endl
              << "2. Alkoholmentes a hozzavalo?" << std::endl
              << "0. Nincs tobb hozzavalo, kesz az ital" <<std::endl;
}

void Menu::addDrink() {
    std::string Dname;
    std::cout << "Mi legyen az ital neve?" << std::endl;
    std::cin >> Dname;
    char ans = 1;
    size_t i = 1;
    double volume = 0;
    double voltmp = 0;
    double alcvoltmp = 0;
    std::vector<Liquid*> ings;
    std::string ingtmp;

    while(ans != 0) {
        addDmenu();
        std::cin >> ans;
        switch (ans) {
            case '1': {
                std::cout << "Mi a hozzavalo neve?" << std::endl;
                std::cin >> ingtmp;
                std::cout << "Hany % alkoholt tartalmaz?" << std::endl;
                std::cin >> alcvoltmp;
                std::cout << "Hany dL kell belole?" << std::endl;
                std::cin >> voltmp;
                volume += voltmp;
                ings.push_back(new Alcohol(ingtmp, voltmp, alcvoltmp));
                ++i;
            }
                break;
            case '2': {
                std::cout << "Mi a hozzavalo neve?" << std::endl;
                std::cin >> ingtmp;
                std::cout << "Hany dL kell belole?" << std::endl;
                std::cin >> voltmp;
                volume += voltmp;
                ings.push_back(new Liquid(ingtmp, voltmp));
                ++i;
            }
                break;
            case '0': {
                Drink d(Dname, ings, i, volume);
                d.writeToFile(d);
                ans = 0;
            }
                break;
            default:break;
        }
    }

}

void Menu::showIngs() {
    std::ifstream file("Alapanyagok.txt");
    std::string str;
    size_t i = 1;
    while (std::getline(file, str)) {
        std::cout << i << " " << str << std::endl;
        i++;
    }
    std::cout  << std::endl;
}

void Menu::choose() {
    char ans = 1;

    while(ans != 0) {
    std::cin >> ans;
        switch (ans) {
            case '1':
                Menu::showMenu1();
                while(ans != '0') {
                    std::cin >> ans;
                    switch(ans) {
                        case '1' :
                            showDrinks();
                            showMenu1();
                            break;
                        case '2' :
                            addDrink();
                            showMenu1();
                            break;
                        case '3' :
                            showMenu1();
                            break;
                        case '0' :
                            Menu::showMenu();
                            break;
                        default : break;
                    }
                }

                break;
            case '2':
                Menu::showMenu2();
                while(ans != '0') {
                    std::cin >> ans;
                    switch(ans) {
                        case '1' :
                            showDrinks();
                            break;
                        case '2' :break;
                        case '3' :break;
                        case '0' :
                            Menu::showMenu();
                            break;
                        default : break;
                    }
                }
                break;
            case '0': ans = 0;
                      break;
            default : std::cout << "Ervenyes karaktert gepelj be!" << std::endl;
        }
    }
}
