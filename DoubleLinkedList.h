

#ifndef PROJ1_DOUBLELINKEDLIST_H
#define PROJ1_DOUBLELINKEDLIST_H
#include "DNode.h"

class DoublyLinkedList {
    dnode *head;
    dnode *tail;
    uint64_t length;
public:
    uint64_t getLength() const {
        return length;
    }

    // Linked List Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    // Linked List add function
    void add(Student *data) { // Same as pushBack
        pushBack(data);
    }

    // Linked List push back
    void pushBack(Student *data) {
        if (head) {  // Check head not equal to nullptr ( linked list is not empty )
            tail->setNext(new dnode(data));
            tail->getNext()->setPrev(tail);
            tail = tail->getNext();
            length++;
        } else { // if linkedlist empty
            head = new dnode(data);
            tail = head;
            length++;
        }
    }

    // Linked List push front
    void pushFront(Student *data) {
        if (head) {
            head = new dnode(data, head);
            length++;
        } else {
            head = new dnode(data, head);
            tail = head;
            length++;
        }
    }

    // Linked list insert after
    void insertAfter(dnode *referenceNode, Student *data) {
        if (!head) {
            return;
        }
        dnode *p = head;
        while (p) {
            if (p == referenceNode) {
                break;
            }
            p = p->getNext();
        }
        if (!p) {
            return;
        }
        p->setNext(new dnode(data, p->getNext()));
        p->getNext()->setPrev(p);
        if (p == tail) {
            tail = p->getNext();
        } else {
            p->getNext()->getNext()->setPrev(p->getNext());
        }
        length++;
    }


    // Linked List print function
    void printLinkedList() {
        dnode *p = head;
        while (p != nullptr) {
            std::cout << p->getData() << std::endl;
            p = p->getNext();
        }
    }

    // Linked List print in reverse order function
    void printRevers() {
        dnode *p = tail;
        while (p != nullptr) {
            std::cout << p->getData() << std::endl;
            p = p->getPrev();
        }
    }

    // Access the linked list like an array
    dnode *at(uint64_t index) {
        if (index >= length) {
            throw std::runtime_error("Error: you should not access an element outside of the range.");
        }
        dnode *p = head;
        for (uint64_t i = 0; i < index; i++)
        {
            p = p->getNext();
        }
        return p;
    }

    // Once we take the overloading with reference, you can uncomment this definition and uncomment the previous definition
//    dnode<T> &at(uint64_t index) {
//        if (index >= length) {
//            throw std::runtime_error("Error: you should not access an element outside of the range.");
//        }
//        dnode<T> *p = head;
//        for (uint64_t i = 0; i < index; i++) p = p->getNext();
//        return *p;
//    }

    // Use array notation to access the linked list like an array
    dnode *operator[](uint64_t index) {
        return at(index);
    }

    // Once we take the overloading with reference, you can uncomment this definition and uncomment the previous definition
//    dnode<T> &operator[](uint64_t index) {
//        return at(index);
//    }


    // Delete a dnode
    void deleteNode(dnode *nodeToBeDeleted) {
        if (!head) {
            return;
        }
        if (nodeToBeDeleted == head) {
            head = head->getNext();
            head->setPrev(nullptr);
            delete nodeToBeDeleted;
        } else {
            dnode *p = head;
            while (p->getNext()) {
                if (p->getNext() == nodeToBeDeleted) {
                    p->setNext(nodeToBeDeleted->getNext());
                    if (p->getNext() != nullptr) {
                        p->getNext()->setPrev(p);
                    } else {
                        tail = p;
                    }
                    delete nodeToBeDeleted;
                    length--;
                    break;
                }
                p = p->getNext();
            }
        }
    }

    // Linked List Destructor
    virtual ~DoublyLinkedList() {
        dnode *p = nullptr;
        while (head) {
            p = head;
            delete p;
            head = head->getNext();
        }
    }

protected:
    dnode *getHead() const {
        return head;
    }

    dnode *getTail() const {
        return tail;
    }

    void setHead(dnode *head) {
        DoublyLinkedList::head = head;
    }

    void setTail(dnode *tail) {
        DoublyLinkedList::tail = tail;
    }

};
#endif //PROJ1_DOUBLELINKEDLIST_H
