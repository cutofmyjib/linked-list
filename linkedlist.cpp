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
/* ** ** ** ** **  TODO REMOVE LOGS ** ** ** ** ** */

#include "linkedlist.h"

DoublyLinkedList::DoublyLinkedList()
{
    count = 0;
    head = NULL;
    tail = NULL;
}
 
DoublyLinkedList::~DoublyLinkedList()
{
    clear();
    cout << "destru " << count << endl;
}

bool DoublyLinkedList::addNode(int addId, string addData)
{
    bool isAdded = false;
    Node *addNode = new Node(addId, addData);

    // list empty
    if (head == nullptr)
    {
        // A new node in the beginning
        head = addNode;
        tail = addNode;
        head->back = nullptr;
        count++;
        isAdded = true;
    } 
    else if (head->id >= addId)
    {
        // addNode id lesser than head node id, then add before head node
        addNode->forward = head;
        addNode->forward->back = addNode;
        head = addNode;
        count++;
        isAdded = true;
    }
    else
    {
        // addNode id less than head node
        Node *currentPtr;
        currentPtr = head;

        // locate where to insert addNode
        while ((currentPtr->forward != nullptr) && (currentPtr->forward->id < addId))
        {
            currentPtr = currentPtr->forward;
        }

        //currentPtr is now located before the position where addNode needs to go
        //assign addNode forward pointer to what currentPtr is pointing forward to
        addNode->forward = currentPtr->forward;

        // addNode inserted
        // tail is addNode when currentPtr forward is not pointing to anything
        if (currentPtr->forward != NULL)
        {
            addNode->forward->back = addNode;
        }
        else
        {
            tail = addNode;
        }
        currentPtr->forward = addNode;
        addNode->back = currentPtr;

        count++;
        isAdded = true;
    } 

    return isAdded;
}

bool DoublyLinkedList::clear()
{
    bool isClear = false;
    Node *nodePtr = head; 
    while (nodePtr != nullptr)
    {
        
        // garbage keeps track of node to be deleted
        Node *garbage = nodePtr;
        // cout << garbage << endl;

        // Move on to the prev node, if any        
        nodePtr = nodePtr->forward; 

        //Delete the "garbage" node 
        if (garbage)
        {
            count--;
            delete garbage;
        }

        isClear = true;
    }
    return isClear;
}

bool DoublyLinkedList::deleteNode(int targetId)
{
    DataNode *targetNode = new DataNode();
    Node *currentPtr;
    bool isFound = getNode(targetId, targetNode);
    bool isDeleted = false;

    if (!head || !isFound)
    {
        return isDeleted;
    }
    
    //if deleting first node
    if (head->id == targetId)
    {
        currentPtr = head;
        head = head->forward;
        delete currentPtr;
        count--;
        isDeleted = true;
    }
    else
    {
        currentPtr = head;

        while (currentPtr != nullptr)
        {
            if (currentPtr->id == targetId)
            {
                
                //if tail, set forward to null
                if (currentPtr->forward == nullptr)
                {
                    currentPtr->back->forward = nullptr;
                    currentPtr->forward = nullptr;
                }
                else
                {
                    currentPtr->back->forward = currentPtr->forward;
                    currentPtr->forward->back = currentPtr->back;
                }
                
                delete currentPtr;
                
                count--;
                isDeleted = true;
                return isDeleted;
            }

            currentPtr = currentPtr->forward;
        }
    }

    return isDeleted;
}

int DoublyLinkedList::getCount()
{
    return count;
}

bool DoublyLinkedList::getNode(int nodeId, DataNode *returnNode)
{
    Node *nodePtr;
    nodePtr = head;

    bool isFound = false;

    if (!((nodeId >= head->id) && (nodeId <= tail->id)))
    {
        return isFound;
    }

    while ((nodePtr != nullptr) && (nodePtr->id <= nodeId))
    {
        if (nodePtr->id == nodeId) {
            returnNode->id = nodePtr->id;
            returnNode->data =  nodePtr->data;
            isFound = true;
            return isFound;
        }

        nodePtr = nodePtr->forward;
    }

    return isFound;
}

void DoublyLinkedList::printList(bool flag)
{
    Node *nodePtr;   
    flag ? nodePtr = head : nodePtr = tail; 

    while (nodePtr != nullptr)
    {
        if (flag == true)
        { 
            cout << nodePtr->id << endl;
            nodePtr = nodePtr->forward;
        }
        else 
        {
            cout << nodePtr->id << endl;
            nodePtr = nodePtr->back;
        }
    }  

}

