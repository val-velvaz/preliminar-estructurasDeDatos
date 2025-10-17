#pragma once
#include <string>
#include <iostream>

class Quantity {
private:
    std::string value;

public:
    Quantity();
    Quantity(const std::string& value);

    std::string getValue() const;
    void setValue(const std::string& value);

    std::string toString() const;

    friend std::ostream& operator << (std::ostream& os, const Quantity& quantity);
    friend std::istream& operator >> (std::istream& is, Quantity& quantity);
};