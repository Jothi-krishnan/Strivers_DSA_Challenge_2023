#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node (int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *head = num2;
    int carry = 0;

    Node* prevNum2 = NULL;
    while(num1 != NULL && num2 != NULL)
    {
        int sum = carry + num1->data + num2->data;
        num2->data = sum%10;
        carry = sum/10;

        prevNum2 = num2;
        num1 = num1->next;
        num2 = num2->next;
    }

    while(num2 != NULL)
    {
        int sum = carry + num2->data;
        num2->data = sum%10;
        carry = sum/10;
        prevNum2 = num2;
        num2 = num2->next;
    }

    while(num1 != NULL)
    {
        prevNum2->next = num1;
        int sum = carry + num1->data;
        num1->data = sum%10;
        carry = sum/10;
        prevNum2 = num1;
        num1 = num1->next;
    }

    while(carry > 0)
    {
        prevNum2->next = new Node(carry%10);
        carry /= 10;
        prevNum2 = prevNum2->next;
    }

    return head;
}
