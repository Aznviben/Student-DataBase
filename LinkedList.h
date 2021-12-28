
#ifndef PROJ1_LINKEDLIST_H
#define PROJ1_LINKEDLIST_H
#include "Node.h"
#include "Course.h"

class LinkedList {
    node *head;
    node *tail;
    uint64_t length;
public:
    uint64_t getLength() const {
        return length;
    }


    // Linked List Constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Linked List add function
    void add(Course *data) {
        pushBack(data);
    }

    // Linked List push back
    void pushBack(Course *data) {
        if (head) {
            tail->setNext(new node(data));
            tail = tail->getNext();
            length++;
        } else {
            head = new node(data);
            tail = head;
            length++;
        }
    }

    // Linked List push front
    void pushFront(Course *data) {
        if (head) {
            head = new node(data, head);
            length++;
        } else {
            head = new node(data, head);
            tail = head;
            length++;
        }
    }


    void insertAfter(node *referenceNode, Course *data) {
        if (!head) {
            return;
        }
        node *p = head;
        while (p) {
            if (p == referenceNode) {
                break;
            }
            p = p->getNext();
        }
        if (!p) {
            return;
        }
        p->setNext(new node(data, p->getNext()));
        if (p == tail) {
            tail = p->getNext();
        }
        length++;
    }



    void printLinkedList() {
        node *p = head;
        while (p != nullptr) {
            std::cout << p->getData() << std::endl;
            p = p->getNext();
        }
    }

    node *at(uint64_t index) {
        if (index >= length) {
            throw std::runtime_error("Error: you should not access an element outside of the range.");
        }
        node *p = head;
        for (uint64_t i = 0; i < index; i++) {
            p = p->getNext();
        }
        return p;
    }



    node *operator[](uint64_t index) {
        return at(index);
    }
    void deleteNode(node *nodeToBeDeleted) {
        if (!head) {
            return;
        }
        if (nodeToBeDeleted == head) {
            head = head->getNext();
            delete nodeToBeDeleted;
        } else {
            node *p = head;
            while (p->getNext()) {
                if (p->getNext() == nodeToBeDeleted) {
                    p->setNext(nodeToBeDeleted->getNext());
                    delete nodeToBeDeleted;
                }
                p = p->getNext();
            }
        }
    }


    virtual ~LinkedList() {
        node *p = nullptr;
        while (head) {
            p = head;
            delete p;
            head = head->getNext();
        }
    }


};


#endif //PROJ1_LINKEDLIST_H
