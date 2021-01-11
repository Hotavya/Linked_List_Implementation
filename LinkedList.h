/*=============================
 TEMPLATED CLASS LINKED LIST
 =============================*/

#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
public:
    LinkedList();                   //Constructor
    ~LinkedList();                  //Destructor
    void printList() const;         //printList function
    void append(const T& data);     //append function
    void prepend(const T& data);    //prepend function
    bool removeFront();             //removeFront function
    void insert(const T& data);     //insert function
    bool remove(const T& data);     //remove function
    bool find(const T& data);       //find function
    bool isEmpty() const;           //isEmpty function
    T getFirst() const;             //getFirst functon
    T getLast() const;              //getLast function
    

};

/*======================
 DEFAULT CONSTRUCTOR
 Sets head and tail member
 variable to nullptr.
 =======================*/
template <class T>
LinkedList<T>::LinkedList ()
{
    head = nullptr;
    tail = nullptr;
}

/*==================================
DESTRUCTOR
The destructor deletes all the nodes
in the linked list one by one.
====================================*/
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *ptr = head;
    Node<T> *nextNode;
    
    while (ptr != nullptr)
    {
        nextNode = ptr->link;
        delete ptr;
        ptr = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

/*=============================
 PRINTLIST FUNCTION
 This function prints the data
 stored in each node. Returns
 Nothing.
 ==============================*/
template <class T>
void LinkedList<T>::printList() const
{
    Node<T> *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}

/*================================
 APPEND FUNCTION
 This function receives a const
 T by reference. It adds a new node
 to the end of the list.
 Returns Nothing.
 =================================*/
template <class T>
void LinkedList<T>::append(const T& data)
{
    Node<T> *ptr = new Node<T>(data, nullptr);
    if (!head)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        tail->link = ptr;
        tail = ptr;
    }
}

/*=================================
 PREPEND FUNCTION
 This function receives a const
 T by reference. It adds a new node
 to the beginning of the list.
 Returns Nothing.
 ==================================*/
template <class T>
void LinkedList<T>::prepend(const T& data)
{
    Node<T> *ptr = new Node<T>(data, nullptr);
    if (!head)
    {
        head = ptr;
        tail = ptr;
    }
    else
    {
        ptr->link = head;
        head = ptr;
    }
}

/*==================================
 REMOVE FRONT FUNCTION
 Removes the first node in the list.
 Receives nothing and returns a
 boolena value.
 ==================================*/
template <class T>//If head is nullptr return false?
bool LinkedList<T>::removeFront()
{
    if(!head)
        return false;
    Node<T> *ptr = head->link;
    delete head;
    head = ptr;
    return true;

}

/*==================================
 INSERT FUNCTION
 This function receives a const
 T by reference. It inserts the value
 in the linked list in correct order.
 Returns Nothing.
 ===================================*/
template <class T>
void LinkedList<T>::insert(const T& data)
{
    Node<T> *ptr = new Node<T> (data, nullptr);
    Node<T> *previous = nullptr, *pptr = head;
    if (!head)
    {
        head = ptr;
        tail = ptr;
        return;
    }
    if(ptr->data < head->data)
    {
        ptr->link = head;
        head = ptr;
        return;
    }
    while (pptr!=nullptr && pptr->data < data)
    {
        previous = pptr;
        pptr = pptr->link;
    }
    if(pptr == nullptr)
    {
        tail->link = ptr;
        tail = ptr;
    }
    else
    {
        previous->link = ptr;
        ptr->link = pptr;
        
    }
}

/*====================================
 REMOVE FUNCTION
 This function receives a const
 T by reference. It removes the node
 containing the value passed as argument.
 If the node is removed it returns true
 else returns false.
 =====================================*/
template <class T>
bool LinkedList<T>::remove(const T& data)
{
    Node<T>*ptr = head, *previous = nullptr;
    if(!head)
        return false;
    while(ptr!=nullptr && ptr->data != data)
    {
        previous = ptr;
        ptr = ptr->link;
    }
    if(ptr == head)
    {
        ptr = head->link;
        delete head;
        head = ptr;
        return true;
    }
    else if(ptr == nullptr)
    {
        return false;
    }
    else
    {
        previous->link = ptr->link;
        delete ptr;
        if(ptr->link == nullptr)
            tail = previous;
        return true;
    }
    return false;
}

/*=================================
 FIND FUNCTION
 This function receives a const
 T by reference. Searches for the
 value passed as argument in linked
 list. If found returns true else
 returns false.
 ==================================*/
template <class T>
bool LinkedList<T>::find(const T& data)
{
    if(!head)
        return false;
    Node<T> *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->data == data)
            return true;
        ptr = ptr->link;
    }
    return false;
}

/*==============================
 IS EMPTY FUNCTION
 Checks if linked list is empty.
 If it is empty, returns true else
 returns false.
 ===============================*/
template <class T>
bool LinkedList<T>::isEmpty() const
{
    if (!head)
        return true;
    else
        return false;
}

/*===========================
 GET FIRST FUNCTION
 Returns the value stored in
 first node of linked list.
 Returns a data of type T.
 ===========================*/
template <class T>
T LinkedList<T>::getFirst() const
{
    return head->data;
}

/*=========================
 GET LAST FUNCTION
 Returns value stored in
 last node of linked list.
 ==========================*/
template <class T>
T LinkedList<T>::getLast() const
{
    return tail->data;
}


#endif
