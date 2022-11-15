#pragma once

class Node
{
public:
    int data;
    Node* next;

    // default constructor
    Node() : data(0), next(nullptr) { }

    // parameterised constructor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
    Node* head;
public:
    // default constructor
    LinkedList() : head(nullptr) { }

    // function to insert a node
    // at the end of linked list
    void insertNode(int);

    // function to print
    // the linked list
    void printList();

    // function to delete
    // node at given position
    void deleteNode(int);
};
