#include "LinkedList.hpp"
#include <iostream>

// Function to delete node
void LinkedList::deleteNode(int nodeOffset)
{
    Node *temp1 = head, *temp2 = nullptr;
    int ListLen = 0;
    if (!head)
    {
        std::cout << "List is empty";
        return;
    }

    // Find length of the linked list
    while (temp1)
    {
        temp1 = temp1->next;
        ++ListLen;
    }
}
