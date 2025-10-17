#pragma once
#include <string>
#include <iostream>

class Duration {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize();

public:
    Duration();
    Duration(int h, int m, int s);

    int getHours() const;
    void setHours(int h);

    int getMinutes() const;
    void setMinutes(int m);

    int getSeconds() const;
    void setSeconds(int s);

    int getTotalInSeconds() const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Duration& duration);
    friend std::istream& operator>>(std::istream& is, Duration& duration);
};