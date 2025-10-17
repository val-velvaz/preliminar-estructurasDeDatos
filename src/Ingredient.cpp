#include "Ingredient.hpp"

Name Ingredient::getName() const {
    return this->ingredientName;
}

void Ingredient::setName(const Name& name) {
    this->ingredientName = name;
}

Quantity Ingredient::getQuantity() const {
    return this->quantity;
}

void Ingredient::setQuantity(const Quantity& quantity) {
    this->quantity = quantity;
}

std::string Ingredient::toString() const {
    return this->getName().toString() + " (" + this->getQuantity().toString() + ")";
}

std::ostream& operator << (std::ostream& os, const Ingredient& ingredient) {
    os << ingredient.getName() << std::endl;
    os << ingredient.getQuantity();
    return os;
}

std::istream& operator >>(std::istream& is, Ingredient& ingredient) {
    Name name;
    Quantity quantity;
    is >> name;
    is >> quantity;
    ingredient.setName(name);
    ingredient.setQuantity(quantity);
    return is;
}