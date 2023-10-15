/*
 * This is a doubly linked list program. 
 */

/*
 * File name: linkedlist.cpp
 * Author: Swapnil Singh
 */

 #include "linkedlist.h"

 LinkedList::LinkedList() 
    : head{NULL} 
{}

void LinkedList::printList(bool printBackwards) {

    Node *current = head; // start a "tracking" pointer by pointing it head

    if (!printBackwards) {
        // traverse it forward
        while(current){       // as long as we're not at the end, keep going
            cout << current->data.id << ": " << current->data.data << endl;
            current = current->next; // go to the next node
        }
        cout << endl;
    } else {
        // traverse it backward
        // but first you have to find the tail
        bool tail = false; // we're not at the tail yet
        while (current && !tail) { // find the tail
            if (current->next) {
                current = current->next;
            } else {
                tail = true; // found the tail
            }
        }
        // now traverse it backward
        while (current){
           cout << current->data.id << ": " << current->data.data << endl;
           current = current->prev;
        }
    }

}
bool LinkedList::isValidId(int id) {
    return (id > 0);
}


bool LinkedList::isValidData(string* data) {
    return !data->empty();
}

bool LinkedList::addNode(int id, string* data) {
    bool nodeAdded = false;
    bool isDuplicate = false;
    if (isValidId(id) && isValidData(data)) {
        Node *newNode = new Node;
        newNode->data.id = id;
        newNode->data.data = *data;

        if(head = NULL) {
            head = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;

            nodeAdded = true;
        } else {
            Node *current = head;
            while(current->next != NULL && id > current->data.id) {
                current = current->next;
            }
            //Checking for duplicates
            if (id == current->data.id) {
                isDuplicate = true;
            }

            // tail case
            if (!isDuplicate && current->next == NULL) {
                newNode->next = NULL;
                newNode->prev = current;
                current->next = newNode;
                nodeAdded = true;
            }
            // head case
            else if (!isDuplicate && current->prev == NULL) {
                newNode->prev = NULL;
                newNode->next = current;
                current->prev = newNode;
                head = newNode;
                nodeAdded = true;
            }
            // general case
            else if (!isDuplicate) {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                nodeAdded = true;
            }
        }

        
    }
    
    return nodeAdded;
}
bool LinkedList::deleteNode(int id) {
    bool deleted = false;
    Node *current = head;
    
    if (isValidId(id) && current != NULL){
        // head case
        if (id == current->data.id) {
            current->next->prev = NULL;
            delete current;
            deleted = true;
        }

        while(current->next != NULL && id > current->data.id) {
            current = current->next;
        }

        // tail case
        if (current->next == NULL && id == current->data.id) {
            current->prev->next = NULL;
            delete current;
            deleted = true;
        }

        // General case
        else if (id == current->data.id) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            deleted = true;
        }
    }

    return true;
}
bool LinkedList::getNode(int id, Data* data){
    bool found = false;
    if (isValidId(id)) {
        Node *current = head;
        while(current != NULL && id > current->data.id) {
            current = current->next;
        }

        if (id == current->data.id) {
            *data = current->data;
            found = true;
        }
    }

    return found;
}

int LinkedList::getCount(){
    Node *current = head;
    int count = 0;
    while(current = current->next) {
        count++;
    }
    return count;

}

bool LinkedList::clearList(){
    bool cleared = false;
    Node *current = head;
    while(current = current->next) {
        current->next->prev = NULL;
        delete current;
        cleared = true;
    }
    return cleared;
}

bool LinkedList::exists(int id) {
    bool found = false;
    if (isValidId(id)) {
        Node *current = head;
        while(current != NULL && id > current->data.id) {
            current = current->next;
        }
        if (id == current->data.id) {
            found = true;
        }
    }   
    
    return found;
}