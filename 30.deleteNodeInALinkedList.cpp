#include<bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int> *prev = NULL;
    while(node->next != NULL)
    {
        node->data = node->next->data;
        prev = node;
        node = node->next;
    }

    if(prev != NULL)
        prev->next = NULL;
    else{
        node = NULL;
    }   
}