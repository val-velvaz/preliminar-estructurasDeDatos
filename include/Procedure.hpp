#pragma once
#include <string>
#include <iostream>

class Procedure {
private:
    std::string steps;

public:
    Procedure();
    Procedure(const std::string& steps);

    std::string getSteps() const;
    void setSteps(const std::string& steps);

    std::string toString() const;

    friend std::ostream& operator << (std::ostream& os, const Procedure& procedure);
    friend std::istream& operator >> (std::istream& is, Procedure& procedure);
};