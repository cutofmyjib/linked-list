/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is the stack header file.
***********************************************************/

#include <iostream>     /* cout, endl, for printList */

//this is a directive that prevents .h files from being included more than once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
using std::string;
using std::cout;
using std::endl;

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
private:
    int count;
    Node *head;
    
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool addNode(int, string);
    bool clear();
    bool deleteNode(int);
    int getCount();
    bool getNode(int, DataNode*);
    void printList(bool flag=true);
};

#endif //LINKED_LIST_H