/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is the main cpp file.
***********************************************************/

#include "main.h"

int main() {

    DoublyLinkedList *doubly = new DoublyLinkedList();
    doubly->addNode(1, "testdata");
    doubly->addNode(2, "testdata2");
    doubly->addNode(0, "testdata0");
    doubly->addNode(4, "testdata4");
    doubly->addNode(4, "testdata4");

    Node *nodePtr = doubly->head;
    while (nodePtr != nullptr)
    {
        cout << nodePtr->id << endl;
        nodePtr = nodePtr->forward;
        
    }    

    cout << "---------" << endl;
    Node *tailPtr = doubly->tail;
    while (tailPtr != nullptr)
    {
        cout << tailPtr->id << endl;
        tailPtr = tailPtr->back;
    }

    return 0;
}
