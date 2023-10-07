#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    int startsWith = 0;
    int endsWith = 0;

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

    void changeStartsWith(int sum)
    {
        startsWith += sum;
    }

    void changeEndsWith(int sum)
    {
        endsWith += sum;
    }

    int getEndsWith()
    {
        return endsWith;
    }

    int getStartsWith()
    {
        return startsWith;
    }
};


class Trie{
    private:
        Node *root;
    public:

    Trie(){
        root = new Node;
    }

    void insert(string &word){
        int n = word.size();
        Node *node = root;
        for(int i = 0; i<n; i++)
        {
            if(!node->isPresent(word[i]))
            {
                node->putLink(word[i], new Node);
            }

            node = node->getLink(word[i]);
            node->changeStartsWith(1);
        }

        node->changeEndsWith(1);
    }

    int countWordsEqualTo(string &word){
        int n = word.size();
        Node *node = root;

        for(int i = 0; i<n; i++)
        {
            if(!node->isPresent(word[i]))
                return 0;
            
            node = node->getLink(word[i]);
        }

        return node->getEndsWith();
    }

    int countWordsStartingWith(string &word){
        int n = word.size();
        Node *node = root;

        for(int i = 0; i<n; i++)
        {
            if(!node->isPresent(word[i]))
                return 0;

            node = node->getLink(word[i]);
        }

        return node->getStartsWith();
    }

    void erase(string &word){
        int n = word.size();
        Node *node = root;

        for(int i = 0; i<n; i++)
        {
            if(!node->isPresent(word[i]))
                return;

            node = node->getLink(word[i]);
            node->changeStartsWith(-1);
        }

        node->changeEndsWith(-1);
    }
};