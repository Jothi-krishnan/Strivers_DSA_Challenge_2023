#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
        
    Node<int> *head;

    if(first->data > second->data)
    {
        Node<int> *tmp = first;
        first = second;
        second = tmp;
    }

    head = first;

    while(first != NULL && second != NULL)
    {
        Node<int> *tmp = NULL;
        while(first != NULL && first->data <= second->data)
        {
            tmp = first;
            first = first->next;
        }

        tmp->next = second;

        Node<int> *t  = first;
        first = second;
        second = t;
    }    

    return head;
}