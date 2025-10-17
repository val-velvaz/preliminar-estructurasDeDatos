#include "Author.hpp"

Author::Author() {}

Author::Author(const Name& name) {
    this->setName(name);
}

Name Author::getName() const {
    return this->authorName;
}

void Author::setName(const Name& name) {
    this->authorName = name;
}

std::string Author::toString() const {
    return this->getName().toString();
}

std::ostream& operator << (std::ostream& os, const Author& author) {
    os << author.getName();
    return os;
}

std::istream& operator >> (std::istream& is, Author& author) {
    Name name;
    is >> name;
    author.setName(name);
    return is;
}