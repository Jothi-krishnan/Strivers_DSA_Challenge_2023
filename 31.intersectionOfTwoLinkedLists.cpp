#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};


Node* findIntersection(Node *firstHead, Node *secondHead)
{
    int len1 = 1, len2 = 1;

    Node *curr = firstHead;
    while(curr != NULL)
    {
        len1++;
        curr = curr->next;
    }

    curr = secondHead;
    while(curr != NULL)
    {
        len2++;
        curr = curr->next;
    }

    Node *a = firstHead;
    Node *b = secondHead;

    while(len1 > len2)
    {
        len1--;
        a = a->next;
    }

    while(len2 > len1)
    {
        len2--;
        b = b->next;
    }


    while(a != b)
    {
        a = a->next;
        b = b->next;
    }

    return a;
    
}