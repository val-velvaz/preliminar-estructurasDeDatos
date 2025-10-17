#include "Quantity.hpp"

Quantity::Quantity() : value("") {}

Quantity::Quantity(const std::string& value) {
    this->setValue(value);
}

std::string Quantity::getValue() const {
    return this->value;
}

void Quantity::setValue(const std::string& value) {
    this->value = value;
}

std::string Quantity::toString() const {
    return this->getValue();
}

std::ostream& operator << (std::ostream& os, const Quantity& quantity) {
    os << quantity.getValue() << std::endl;
    return os;
}

std::istream& operator >> (std::istream& is, Quantity& quantity) {
    std::string value;
    std::getline(is, value);
    quantity.setValue(value);
    return is;
}