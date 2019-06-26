/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is the main cpp file.
***********************************************************/

#include "main.h"

int main() {

    DoublyLinkedList *doubly = new DoublyLinkedList();
    doubly->addNode(4, "testdata4");
    doubly->addNode(1, "testdata1");
    doubly->addNode(2, "testdata2");
    doubly->addNode(0, "testdata0");
    doubly->addNode(5, "testdata5");
    doubly->addNode(3, "testdata3");

    cout << "Print list ascending order" << endl;
    doubly->printList();

    cout << "doubly count should be 6: " << (doubly->getCount() == 6 ? "true" : "false") << endl;
    cout << endl;

    DataNode *targetNode0 = new DataNode();
    bool isFound0 = doubly->getNode(0, targetNode0);
    cout << "Get node 0 "<< (isFound0 ? "is found" : "is not found") << " == is found" << endl;
    cout << ("testdata0" == targetNode0->data ? "true" : "false") << " == true" << endl;
    cout << endl;

    DataNode *targetNode13 = new DataNode();
    bool isFound13 = doubly->getNode(13, targetNode13);
    cout << "Get node 13 "<< (isFound13 ? "is found" : "is not found") << " == is NOT found" << endl;
    cout << ("testdata3" == targetNode13->data ? "true" : "false") << " == false" << endl;
    cout << endl;

    DataNode *targetNode5 = new DataNode();
    bool isFound5 = doubly->getNode(5, targetNode5);
    cout << "Get node 5 "<< (isFound5 ? "is found" : "is not found") << " == is found" << endl;
    cout << ("testdata5" == targetNode5->data ? "true" : "false") << " == true" << endl;
    cout << endl;

    cout << "Delete node 5" << endl;
    doubly->deleteNode(5);
    cout << endl;

    cout << "Delete node 4" << endl;
    doubly->deleteNode(4);
    cout << endl;

    cout << "doubly count should be 4: " << (doubly->getCount() == 4 ? "true" : "false") << endl; 
    
    cout << "Print list descending order" << endl;
    doubly->printList(false);
    
    return 0;
}
