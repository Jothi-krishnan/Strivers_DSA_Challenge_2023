#include <bits/stdc++.h> 
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

LinkedListNode<int>* reverse(LinkedListNode<int> *head)
{
    if(!head|| !head->next)
        return head;

    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *next = head->next;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

LinkedListNode<int>* middle(LinkedListNode<int> *head)
{
    LinkedListNode<int> *slow = head, *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(!head)
        return true;

    LinkedListNode<int> *p1 = head;
    LinkedListNode<int> *mid = middle(head);
    LinkedListNode<int> *p2 = reverse(mid);

    while(p1 && p2)
    {
        if(p1->data != p2->data)
            return false;

        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}