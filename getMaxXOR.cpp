#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[2];

    bool isPresent(int i)
    {
        return (links[i] != NULL);
    }

    void putLink(int i, Node * node)
    {
        links[i] = node;
    }

    Node* getLink(int i)
    {
        return links[i];
    }
};

class Trie{
    private:
    Node *root;

public:
    Trie(){
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for(int i = 31; i>=0; i--)
        {
            if((num >> i) & 1)
            {
                if(!node->isPresent(1))
                    node->putLink(1, new Node());
                
                node = node->getLink(1);
            }
            else{
                if(!node->isPresent(0))
                    node->putLink(0, new Node());

                node = node->getLink(0);
            }
        }
    }

    int getMaxXOR(int x)
    {
        int ans =0;
        Node *node = root;
        for(int i = 31; i>= 0; i--)
        {
            if((x >> i) & 1)
            {
                if(node->isPresent(0))
                {
                    ans += (1<<i);
                    node = node->getLink(0);
                }
                else{
                    node = node->getLink(1);
                }
            }
            else{
                if(node->isPresent(1))
                {
                    ans += (1 << i);
                    node = node->getLink(1);
                }
                else{
                    node = node->getLink(0);
                }
            }
        }

        return ans;
    }
};

int maximumXor(vector<int> A)
{
    Trie t;

    int n = A.size();

    for(int i= 0; i<n; i++)
    {
        t.insert(A[i]);
    } 

    int ans = 0;

    for(int i = 0; i<n; i++)
    {
        int currValue = t.getMaxXOR(A[i]);
        ans = max(ans, currValue);
    }

    return ans;
}