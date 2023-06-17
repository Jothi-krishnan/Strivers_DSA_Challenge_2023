#include<bits/stdc++.h>
using namespace std; 

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *rotate(Node *head, int k) {
     Node *prev = NULL, *curr = head;

     int len = 0;
     while(curr != NULL)
     {
          len++;
          prev = curr;
          curr = curr->next;
     }

     prev->next = head;
     curr = head;
     int i = 0;

     k %= len;
     int num = len - k;
     while(i < num)
     {
          i++;
          prev = prev->next;
          curr = curr->next;
     }

     prev->next = NULL;
     return curr;
}