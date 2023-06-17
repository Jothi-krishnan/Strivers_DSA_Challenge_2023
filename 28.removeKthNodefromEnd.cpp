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


Node* removeKthNode(Node* head, int K)
{
    int len = 0;
    Node* curr = head;

    while(curr != NULL)
    {
        len++;
        curr = curr->next;
    }
    
    int tmp = 2;
    Node* prev = head;
    if(prev->next == NULL || K == len)
    {
        return prev->next;
    }
    curr = head->next;

    while(tmp <= len - K)
    {
        tmp++;
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = curr->next;
    return head;
}
