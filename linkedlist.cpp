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

LinkedList::~LinkedList(){
    clearList();
}

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

    if (isValidId(id) && isValidData(data)) {
        Node *current = head;
        Node *newNode;

        if (current == NULL) {
            newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *data;

            head = newNode;
            nodeAdded = true;
        } else {
            while(current->next != NULL && id > current->data.id) {
                current = current->next;
            }

            if (id != current->data.id) {
                // Allocate memory for new Node
                newNode = new Node;
                newNode->data.id = id;
                newNode->data.data = *data;

                if (id < current->data.id && current->prev == NULL) {
                    // head case
                    newNode->prev = NULL;
                    newNode->next = current;
                    current->prev = newNode;
                    head = newNode;
                    nodeAdded = true;
                } else if (id > current->data.id && current->next == NULL) {
                    // tail case
                    newNode->next = NULL;
                    newNode->prev = current;
                    current->next = newNode;
                    nodeAdded = true;
                } else {
                    // general case
                    newNode->next = current;
                    newNode->prev = current->prev;
                    current->prev->next = newNode;
                    current->prev = newNode;
                    nodeAdded = true;
                }
            }
        }
    }
    
    return nodeAdded;
}

bool LinkedList::deleteNode(int id) {
    bool deleted = false;
    
    if (isValidId(id) && head != NULL) {
        Node *current = head;

        while(current->next != NULL && id > current->data.id) {
            current = current->next;
        }

        if (id == current->data.id) {
            if (current->prev == NULL) {
                // head case
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }

                delete current;
                deleted = true;
            } else if (current->next == NULL) {
                // tail case
                current->prev->next = NULL;
                delete current;
                deleted = true;
            } else {
                // general case
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                deleted = true;
            }
        }
    }

    return deleted;
}

bool LinkedList::getNode(int id, Data* data){
    bool found = false;

    if (isValidId(id)) {
        Node *current = head;
        while (current->next != NULL && id > current->data.id) {
            current = current->next;
        }

        if (current != NULL && id == current->data.id) {
            *data = current->data;
            found = true;
        }
    }

    return found;
}

int LinkedList::getCount() {
    Node *current = head;
    int count = 0;

    if (current != NULL) {
        count++;
        while(current = current->next) {
            count++;
        }
    }

    return count;
}

bool LinkedList::clearList() {
    Node *current;

    while (head != NULL) {
        current = head->next;
        delete head;
        head = current;
    }

    return true;
}

bool LinkedList::exists(int id) {
    bool found = false;

    if (isValidId(id)) {
        Node *current = head;
        while(current != NULL && id > current->data.id) {
            current = current->next;
        }

        if (current != NULL && id == current->data.id) {
            found = true;
        }
    }   
    
    return found;
}