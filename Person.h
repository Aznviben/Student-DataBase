#include <iostream>
#include <stdexcept>
using namespace std;
#ifndef PROJ1_PERSON_H
#define PROJ1_PERSON_H


class Person{
private:
    string name;
    uint8_t age = 0;
public:
    Person(){
    name = "noName";
    }
    Person(string name, uint8_t age){
        this->name = name;
        this->age=age;

    }
    void setName(const string &name) {
        Person::name = name;
    }
    const string &getName() const {
        return name;
    }

    uint8_t getAge() const {
        return age;
    }

    void setAge(uint8_t age) {
        Person::age = age;
    }
    void printPerson(){
        cout<<"name is :"<< getName() << endl;
        cout<<"age is :"<< unsigned(getAge()) << endl;
    }
    friend ostream & operator <<( ostream &output, const Person P ) {
        cout<<"name:"<< P.getName() << endl;
        cout<<"age:"<< unsigned(P.getAge()) << endl;

        return output;
    }


};




#endif //PROJ1_PERSON_H
