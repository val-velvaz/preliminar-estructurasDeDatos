#include "Duration.hpp"
#include <stdexcept>

void Duration::normalize() {
    if (this->seconds >= 60) {
        this->minutes += this->seconds / 60;
        this->seconds %= 60;
    }
    if (this->minutes >= 60) {
        this->hours += this->minutes / 60;
        this->minutes %= 60;
    }
}

Duration::Duration() : hours(0), minutes(0), seconds(0) {}

Duration::Duration(int h, int m, int s) {
    if (h < 0 || m < 0 || s < 0) {
        throw std::invalid_argument("El tiempo no puede ser negativo.");
    }
    this->setHours(h);
    this->setMinutes(m);
    this->setSeconds(s);
    this->normalize();
}

int Duration::getHours() const {
    return this->hours;
}

void Duration::setHours(int h) {
    this->hours = (h < 0) ? 0 : h;
}

int Duration::getMinutes() const {
    return this->minutes;
}

void Duration::setMinutes(int m) {
    this->minutes = (m < 0) ? 0 : m;
    this->normalize();
}

int Duration::getSeconds() const {
    return this->seconds;
}

void Duration::setSeconds(int s) {
    this->seconds = (s < 0) ? 0 : s;
    this->normalize();
}

int Duration::getTotalInSeconds() const {
    return this->hours * 3600 + this->minutes * 60 + this->seconds;
}

std::string Duration::toString() const {
    std::string result = "";
    if (this->hours > 0) {
        result += std::to_string(this->hours) + "h ";
    }
    if (this->minutes > 0) {
        result += std::to_string(this->minutes) + "m ";
    }
    if (this->seconds > 0 || (this->hours == 0 && this->minutes == 0)) {
        result += std::to_string(this->seconds) + "s";
    }
    return result;
}

std::ostream& operator << (std::ostream& os, const Duration& duration) {
    os << duration.getHours() << " " << duration.getMinutes() << " " << duration.getSeconds();
    return os;
}

std::istream& operator >> (std::istream& is, Duration& duration) {
    int h, m, s;
    is >> h >> m >> s;
    duration.setHours(h);
    duration.setMinutes(m);
    duration.setSeconds(s);
    duration.normalize();
    return is;
}