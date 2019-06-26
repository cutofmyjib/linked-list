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

    doubly->printList();

    int count = doubly->getCount();
    cout << "doubly count should be 6: " << (count == 6 ? "true" : "false") << endl;

    // DataNode *targetNode0 = new DataNode();
    // bool isFound0 = doubly->getNode(0, targetNode0);
    // cout << "Get node 0 "<< (isFound0 ? "is found" : "is not found") << " == is found" << endl;
    // cout << ("testdata0" == targetNode0->data ? "true" : "false") << " == true" << endl;

    // DataNode *targetNode3 = new DataNode();
    // bool isFound3 = doubly->getNode(3, targetNode3);
    // cout << "Get node 3 "<< (isFound3 ? "is found" : "is not found") << " == is NOT found" << endl;
    // cout << ("testdata3" == targetNode3->data ? "true" : "false") << " == false" << endl;


    DataNode *targetNode5 = new DataNode();
    bool isFound5 = doubly->getNode(5, targetNode5);
    cout << "Get node 5 "<< (isFound5 ? "is found" : "is not found") << " == is found" << endl;
    cout << ("testdata5" == targetNode5->data ? "true" : "false") << " == true" << endl;

    doubly->deleteNode(5);
    doubly->deleteNode(4);
    cout << "doubly count: " << doubly->getCount() << endl;    
    
    doubly->printList();

    // doubly->clear();

    
    
    return 0;
}
