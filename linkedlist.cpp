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

#include "linkedlist.h"

DoublyLinkedList::DoublyLinkedList()
{
    count = 0;
    head = NULL;
}
 
DoublyLinkedList::~DoublyLinkedList()
{
    clear();
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
        if (currentPtr->forward != NULL)
        {
            addNode->forward->back = addNode;
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

    if (!head)
    {
        return true;
    }
    
    //if deleting first node
    if (head->id == targetId)
    {
        currentPtr = head;
        head = head->forward;
        head->back = nullptr;
        delete currentPtr;
        count--;
        return true;
    }

    currentPtr = head;
    while (currentPtr != nullptr)
    {
        if (currentPtr->id == targetId)
        {
            if (currentPtr->forward != nullptr)
            {
                currentPtr->back->forward = currentPtr->forward;
                currentPtr->forward->back = currentPtr->back;
            }
            else
            {
                currentPtr->back->forward = nullptr;   
            }        
        
            delete currentPtr;
            
            count--;
            return true;
        }

        currentPtr = currentPtr->forward;
    }

    return false;
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
    Node *searchPtr = head;
    Node *tailPtr;
     
    if (getCount() > 1) 
    {
        while (searchPtr != nullptr)
        {
            //set tail pointer
            if (searchPtr->forward == nullptr)
            {
                tailPtr = searchPtr;
            }
            searchPtr = searchPtr->forward;
        }
    }
    
    Node *nodePtr = head;

    if (flag)
    {
        while (nodePtr != nullptr)
        {
            cout << nodePtr->id << endl;
            nodePtr = nodePtr->forward;
        }
    }
    else 
    {
        while (tailPtr != nullptr)
        {
            cout << tailPtr->id << endl;
            tailPtr = tailPtr->back;
        }
    }  

}

