#include<bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

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

    bool isEnd(){
        return flag;
    }

    void setEnd()
    {
        flag = true;
    }
};


class Trie {
private:
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
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

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        Node *node = root;

        for(int i = 0; i<n; i++)
        {
            if(!node->isPresent(word[i]))  
                return false;

            node = node->getLink(word[i]);
        }

        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();

        Node *node = root;

        for(int i= 0; i<n; i++)
        {
            if(!node->isPresent(prefix[i]))
                return false;

            node = node->getLink(prefix[i]);
        }

        return true;
    }
};