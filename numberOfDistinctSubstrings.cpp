#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];

    bool isPresent(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void putLink(char ch, Node * node)
    {
        links[ch - 'a'] = node;
    }

    Node* getLink(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    int insert(const string & word)
    {   
        int ans = 0;
        int n = word.size();
        Node * node = root;

        for(int i= 0; i<n; i++)
        {
            if(!node->isPresent(word[i]))
            {
                node->putLink(word[i], new Node());
                ans++;
            }

            node = node->getLink(word[i]);
        }

        return ans;
    }
};

int distinctSubstring(string &word) {
    int n = word.size();

    Trie t;
    string curr = "";

    int ans = 0;
    for(int i = 0; i<n; i++)
    {
        curr = "";
        for (int j = i; j < n; j++) 
        {
            curr.push_back(word[j]);
        }

        int currValue = t.insert(curr);
        ans += currValue;
    }

    return ans;
}