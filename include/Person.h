#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    int id;

public:
    Person();
    Person(int id, const std::string &name);

    // Getters
    int getID() const;
    std::string getName() const;

    // Setters
    void setID(int id);
    void setName(const std::string &name);

    // Virtual function for polymorphism
    virtual void display() const;
};

#endif // PERSON_H
