#pragma once
#include <string>
#include <iostream>

class Name {
private:
    std::string value;

public:
    Name();
    Name(const std::string& value);

    std::string getValue() const;
    void setValue(const std::string& value);

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Name& name);
    friend std::istream& operator>>(std::istream& is, Name& name);
};