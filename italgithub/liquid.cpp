#include "liquid.h"

void Liquid::print() const {
    std::cout << *this << std::endl;
}

void Alcohol::print() const {
    std::cout << *this << " (" << this->getAlcvol() << "%)" << std::endl;
}

std::ostream& Liquid::printFile(std::ostream& os) const {
    os << this->getName() << '\t' << this->getVol();
    return os;
}

std::ostream& Alcohol::printFile(std::ostream& os) const {
    os << this->getName() << "," << this->getAlcvol() << '\t' << this->getVol();
    return os;
}

std::ostream& operator<<(std::ostream& os, const Liquid& L) {
    os << L.getName() << '\t' << L.getVol();
    return os;
}

std::ostream& operator<<(std::ostream& os, const Alcohol& A) {
    os << A.getName() << "," << A.getAlcvol() << '\t' << A.getVol();
    return os;
}

