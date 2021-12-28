#include <iostream>
#include <stdexcept>
#include "Course.h"

#ifndef PROJ1_NODE_H
#define PROJ1_NODE_H
class node {
    Course *data;
    node *next;
public:
    node()
    {
        next = nullptr;
    }
    node(Course *data)
    {
        this->data = data;
        next = nullptr;
    }
    node(Course *data, node *next) {
        this->data = data;
        this->next = next;
    }
    Course *getData(){
        return data;
    }

    void setData(Course *data){
        this->data = data;
    }


    node *getNext() const
    {
        return next;
    }

    void setNext(node *next) {
        node::next = next;
    }

};
#endif //PROJ1_NODE_H
