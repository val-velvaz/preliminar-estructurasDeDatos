#pragma once

#include "Name.hpp"
#include "Quantity.hpp"

#include <iostream>

class Ingredient {
private:
    Name ingredientName;
    Quantity quantity;

public:
    Name getName() const;
    void setName(const Name& name);

    Quantity getQuantity() const;
    void setQuantity(const Quantity& quantity);
    
    std::string toString() const;

    friend std::ostream& operator << (std::ostream& os, const Ingredient& ingredient);
    friend std::istream& operator >> (std::istream& is, Ingredient& ingredient);
};