/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is the main cpp file.
***********************************************************/

#include "main.h"

int main() {

    DoublyLinkedList *doubly = new DoublyLinkedList();
    doubly->addNode(1, "testdata");

    cout << doubly->getCount() << endl;

    return 0;
}
