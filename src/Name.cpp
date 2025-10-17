#include "Name.hpp"

Name::Name() : value("") {}

Name::Name(const std::string& value) {
    this->setValue(value);
}

std::string Name::getValue() const {
    return this->value;
}

void Name::setValue(const std::string& value) {
    this->value = value;
}

std::string Name::toString() const {
    return this->getValue();
}

std::ostream& operator<<(std::ostream& os, const Name& name) {
    os << name.getValue();
    return os;
}

std::istream& operator>>(std::istream& is, Name& name) {
    std::string value;
    std::getline(is, value);
    name.setValue(value);
    return is;
}