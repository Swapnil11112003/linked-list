/*
 * This is a doubly linked list program. 
 */

/*
 * File name: linkedlist.cpp
 * Author: Swapnil Singh
 */

 #include "linkedlist.h"

 LinkedList::LinkedList() {

    head = NULL; // pointer to a Node but pointing at "nothing" for now

    // creates a Node dynamically (this is the common case)
    // creates a Node dynamically
    Node *node1;
    node1 = new Node;

    // creates a Node dynamically
    Node *node2; 
    node2 = new Node;

    // creates a Node dynamically (this is the common case)
    // creates a Node dynamically
    Node *node3;
    node3 = new Node;


    node1->data.id = 1; // put data in node1
    node1->data.data = "Hello"; // put data in node1

   
    node2->data.id = 2; // put data in node2
    node2->data.data = "World"; // put data in node2

    node3->data.id = 3; // put data in node3
    node3->data.data = "Linked Lists are awesome!"; // put data in node3

    // build a linked list (of size 3) out of the nodes made above
    head = node1;         // first point the head at node1
    node1->prev = NULL;   // point node1 prev to NULL because there is no previous
    node1->next = node2;  // point node1 next to node2
    node2->prev = node1;  // point node2 back to node1
    node2->next = node3;  // point node2 next to node3
    node3->prev = node2;  // point node3 back to node2
    node3->next = NULL;   // point node3 next to NULL because there is no next

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

bool LinkedList::addNode(int id, string* data) {
    cout << "STUB: LinkedList::addNode() -> returning true" << endl;
    return true;
}
bool LinkedList::deleteNode(int id) {
    cout << "STUB: LinkedList::deleteNode() -> returning true" << endl;
    return true;

}
bool LinkedList::getNode(int id, Data* data){
    cout << "STUB: LinkedList::getNode() -> returning true" << endl;
    return true;
}

int  LinkedList::getCount(){
    cout << "STUB: LinkedList::getCount() -> returning 1" << endl;
    return 1;

}
bool LinkedList::clearList(){
    cout << "STUB: LinkedList::clearList() -> returning true" << endl;
    return true;

}
bool LinkedList::exists(int id){
    cout << "STUB: LinkedList::exists() -> returning true" << endl;
    return true;

}