/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is where all the linkedlist functions are defined.
■ addNode(int, string) --  Return true or false to indicate success or failure. 
Nodes added must be in ascending order of id. Memory for the node must be allocated inside the linked list object.
■ deleteNode(int) -- pass id to delete. Return true or false to indicate success or failure. Delete the memory the node was using.
■ getNode(int, DataNode*) -- pass this method an id to retrieve a node, and an empty DataNode allocated and passed
by reference from main. If id is found, fill the empty DataNode passed by reference, and return true. If the id is
not found, place a -1 in the id and empty string in the string and return false.
■ printList(bool)
    printList(); //prints forward
    printList(true); //prints forward
    printList(false); //prints backward
■ getCount() -- returns the count of the nodes in the list
■ clear() -- Resets the linked to head=NULL and count=0 AND deletes all allocated
memory.
***********************************************************/


/* ** ** ** ** **  TODO REMOVE LOGS ** ** ** ** ** */
#include <iostream>     /* cout, endl */
using namespace std;

#include "linkedlist.h"

DoublyLinkedList::DoublyLinkedList()
{
    count = 0;
    head = NULL;
    tail = NULL;
}
 
DoublyLinkedList::~DoublyLinkedList()
{
}

bool DoublyLinkedList::addNode(int addId , string addData)
{
    bool isAdded = false;
    Node *nodePtr,
         *newNode,
         *previousNodePtr;

    // list empty, or the first number in the list is greater or equal to addId
    if (head == nullptr || head->id >= addId)
    {
        // A new node added in the beginning
        head = new Node(addId, addData);
        count++;
        isAdded = true;
    }
    else
    {
        // add node before the first node that hasr a value greater than or equal to the number.
        previousNodePtr = head;
        nodePtr = head->forward;

        // locate the node using a pointer
        while (nodePtr != nullptr && nodePtr->id < addId)
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->forward;
        }
        // add node before this pointer
        newNode = new Node(addId, addData);
        newNode->back = previousNodePtr;
        newNode->forward = nodePtr;
        previousNodePtr->forward = newNode;
        nodePtr->back = newNode;

        count++;
        isAdded = true;
    } 

    return isAdded;
}

int DoublyLinkedList::getCount()
{
    return count;
}
