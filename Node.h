/*=========================
 TEMPLATED CLASS NODE
 ==========================*/

#ifndef Node_h
#define Node_h

template <class T>
class Node
{
public:
    T data;
    Node<T> *link;
    Node();
    Node(T, Node<T>*);
    
};

/*======================
 DEFAULT CONSTRUCTOR
 Does Nothing.
 =======================*/
template <class T>
Node<T>::Node()
{
    
}

/*===============================
 OVERLOADED CONSTRUCTOR
 Receives a data of type T
 and a pointer to a node object.
 Assignes the values to data and
 link member variables.
==================================*/
template <class T>
Node<T>::Node(T d, Node *ptr)
{
    data = d;
    link = ptr;
}
#endif
