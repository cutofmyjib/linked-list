/***********************************************************
Name: Diana Lozano
Assignment: 03
Purpose: This is the main cpp file.
***********************************************************/

#include "main.h"

int main() {
    Node *temp = new Node(1, "testdata");

    cout << temp->id << " " << temp->data << endl;
    
    return 0;
}

