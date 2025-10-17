#include "Procedure.hpp"

Procedure::Procedure() : steps("") {}

Procedure::Procedure(const std::string& steps) {
    this->setSteps(steps);
}

std::string Procedure::getSteps() const {
    return this->steps;
}

void Procedure::setSteps(const std::string& steps) {
    this->steps = steps;
}

std::string Procedure::toString() const {
    return this->getSteps();
}

std::ostream& operator<<(std::ostream& os, const Procedure& procedure) {
    os << procedure.getSteps() << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Procedure& procedure) {
    std::string steps;
    std::getline(is, steps);
    procedure.setSteps(steps);
    return is;
}