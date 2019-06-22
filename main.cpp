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

    // Node *nodePtr = doubly->head;
    // while (nodePtr != nullptr)
    // {
    //     cout << nodePtr->id << endl;
    //     nodePtr = nodePtr->forward;
        
    // }    

    // cout << "---------" << endl;
    // Node *tailPtr = doubly->tail;
    // while (tailPtr != nullptr)
    // {
    //     cout << tailPtr->id << endl;
    //     tailPtr = tailPtr->back;
    // }
    DataNode *targetNode0 = new DataNode();
    bool isFound0 = doubly->getNode(0, targetNode0);
    cout << "Get node 0 "<< (isFound0 ? "is found" : "is not found") << " == is found" << endl;
    cout << ("testdata0" == targetNode0->data ? "true" : "false") << " == true" << endl;

    DataNode *targetNode3 = new DataNode();
    bool isFound3 = doubly->getNode(3, targetNode3);
    cout << "Get node 3 "<< (isFound3 ? "is found" : "is not found") << " == is NOT found" << endl;
    cout << ("testdata3" == targetNode3->data ? "true" : "false") << " == false" << endl;


    DataNode *targetNode9 = new DataNode();
    bool isFound9 = doubly->getNode(9, targetNode9);
    cout << "Get node 9 "<< (isFound9 ? "is found" : "is not found") << " == is NOT found" << endl;
    cout << ("testdata9" == targetNode9->data ? "true" : "false") << " == false" << endl;
    return 0;
}
