#include "Person.h"

Person::Person() : id(0), name("") {}

Person::Person(int id, const std::string &name) : id(id), name(name) {}

int Person::getID() const { return id; }
std::string Person::getName() const { return name; }

void Person::setID(int id) { this->id = id; }
void Person::setName(const std::string &name) { this->name = name; }

void Person::display() const {
    std::cout << "ID: " << id << "\n";
    std::cout << "Name: " << name << "\n";
}
