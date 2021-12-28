
#ifndef PROJ1_DNODE_H
#define PROJ1_DNODE_H
#include "Student.h"
class dnode {
    Student *data;
    dnode *next;
    dnode *prev;
public:
    dnode() {
        next = nullptr;
        prev = nullptr;
    }

    dnode(Student *data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }

    dnode(Student *data, dnode *next) {
        this->data = data;
        this->next = next;
        prev = nullptr;
    }

    dnode(Student *data, dnode *next, dnode *prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    Student *getData() const {
        return data;
    }

    void setData(Student *data) {
        dnode::data = data;
    }

    dnode *getNext() const {
        return next;
    }

    void setNext(dnode *next) {
        dnode::next = next;
    }

    void operator=(Student *data) {
        this->data = data;
    }

    dnode *getPrev() const {
        return prev;
    }

    void setPrev(dnode *prev) {
        dnode::prev = prev;
    }
};
#endif //PROJ1_DNODE_H
