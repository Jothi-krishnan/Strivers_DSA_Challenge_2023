#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;

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

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    bool checkFlag()
    {
        return flag;
    }

};

class Trie {
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(const string & word)
    {
        int n = word.size();
        Node *node = root;

        for(int i = 0; i<n; i++)
        {
            if(!node->isPresent(word[i]))
            {
                node->putLink(word[i], new Node());
            }

            node = node->getLink(word[i]);
        }

        node->setEnd();
    }

    bool isCompleteString(const string & word)
    {
        int n = word.size();
        Node * node = root;

        for(int i = 0; i<n; i++)
        {
            if(!node->isPresent(word[i]))
                return false;

            node = node->getLink(word[i]);

            if(node->checkFlag() == false)
                return false;
        }

        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie t;

    for(int i = 0; i<n; i++)
    {
       t.insert(a[i]);
    } 

    string ans = "";

    for(string word : a)
    {
        if(t.isCompleteString(word) && word.size() >= ans.size())
        {
            if(word.size() > ans.size())
                ans = word;
            else if(word.size() == ans.size() && word < ans){
                ans = word;
            }
        }
    }
    
    if(ans.size() == 0)
        return "None";
    else
       return ans;
}