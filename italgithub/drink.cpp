#include "drink.h"

Drink::~Drink() {
    for(size_t i = 0; i < Ings.size(); ++i) {
        delete Ings[i];
    }
    Ings.clear();
  //  delete this;
}

Drink& Drink::operator=(const Drink& rhs) {
        if( this->Ings != rhs.Ings) {
            this->Dname = rhs.getname();
            this->Ings = rhs.Ings;
            this->ingNum = rhs.getingNum();
            this->volume = rhs.getvol();
        }
        return *this;
    }

void Drink::writeToFile(const Drink& d) {
    std::ofstream mf;
    mf.open("Italok.txt", std::ios_base::app);
    mf << d.getname() << '\t';
    for(size_t i = 0; i < d.Ings.size(); ++i) {
        d.getIng(i)->printFile(mf);
        if(i < d.Ings.size()-1)
            mf << '\t';
    }
    mf << '\n';
    mf.close();

}

std::ostream& operator<<(std::ostream& os, const Drink& d) {
    os << d.getname() << std::endl;
    os << "Osszetevok:" << std::endl;
    for(size_t i = 0; i < d.getingNum(); i++)
        //os << *(d.getIng(i));
        d.getIng(i)->print();
    os << "Osszesen " << d.getvol() << "dL" << std::endl;
    return os;
}

