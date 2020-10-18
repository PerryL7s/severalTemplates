#include <bits/stdc++.h>
using namespace std;

class Trie
{
    class TrieNode
    {
        vector<TrieNode *> table;
        bool fin;

    public:
        TrieNode() : table(26, NULL), fin(false) {}
        TrieNode *getChar(char c)
        {
            if (table[c - 'a'] == NULL)
                table[c - 'a'] = new TrieNode;
            return table[c - 'a'];
        }
        TrieNode *findChar(char c)
        {
            return table[c - 'a'];
        }
        bool isEnd()
        {
            return fin;
        }
        void setEnd()
        {
            fin = true;
        }
    };
    TrieNode *root;

public:
    /** Initialize trie here. */
    Trie()
    {
        root = new TrieNode;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        int n = word.size(), i;
        TrieNode *node = root;
        for (i = 0; i < n; ++i)
            node = node->getChar(word[i]);
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        int n = word.size(), i;
        TrieNode *node = root;
        for (i = 0; i < n; ++i)
        {
            if ((node = node->findChar(word[i])) == NULL)
                return false;
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        int n = prefix.size(), i;
        TrieNode *node = root;
        for (i = 0; i < n; ++i)
        {
            if ((node = node->findChar(prefix[i])) == NULL)
                return false;
        }
        return true;
    }
};