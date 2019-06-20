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
    //constructor
    Node(int idParam, string dataParam) 
    {
        id = idParam;
        data = dataParam;
        Node *forward = nullptr;
        Node *back = nullptr;
    }
};



#endif //LINKED_LIST_H