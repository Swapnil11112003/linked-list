/*
 * Header file
 */

/*
 * File name: linkedlist.h
 * Author: Swapnil Singh
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using std::cout;
using std::endl;

#include "data.h"

class LinkedList {
    private:
        Node *head;
        bool isValidId(int);
        bool isValidData(string*);

    public:
        LinkedList();
        ~LinkedList();
        bool addNode(int, string*);
        bool deleteNode(int);
        bool getNode(int, Data*);
        void printList(bool = false);
        int getCount();
        bool clearList();
        bool exists(int);
        
    };

#endif //LINKEDLIST_H