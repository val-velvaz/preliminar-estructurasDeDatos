#pragma once

#include "Name.hpp"
#include <iostream>

class Author {
private:
    Name authorName;

public:
    Author();
    Author(const Name& name);

    Name getName() const;
    void setName(const Name& name);

    std::string toString() const;

    friend std::ostream& operator << (std::ostream& os, const Author& author);
    friend std::istream& operator >> (std::istream& is, Author& author);
};