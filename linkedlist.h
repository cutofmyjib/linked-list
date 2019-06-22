/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is the stack header file.
***********************************************************/

//this is a directive that prevents .h files from being included more than once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using std::string;

struct Node
{
    int id;
    string data;
    Node *forward;
    Node *back;

    //constructor
    Node(int idParam, string dataParam) 
    {
        id = idParam;
        data = dataParam;
        forward = nullptr;
        back = nullptr;
    }
};

struct DataNode
{
    int id;
    string data;
};

class DoublyLinkedList
{
public: //TODO - make private!
    int count;
    Node *head;
    Node *tail;
// public:

    DoublyLinkedList();
    ~DoublyLinkedList();
    bool addNode(int, string);
    bool deleteNode(int);
    bool getNode(int, DataNode*);
    void printList(bool flag=true);
    int getCount();
    bool clear();
};

#endif //LINKED_LIST_H