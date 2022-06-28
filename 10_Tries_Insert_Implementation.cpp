#include <iostream>
#include "09_Tries_Class_implementation.h"
using namespace std;

class Trie
{
    TrieNode *root; // This is created  only once bcz it is releated to object as object is created only once in trie not trienode

public: //  thats why every time we are passing root to helper function
    Trie()
    {
        root = new TrieNode('\0');   // with value 0 at root node
    }

    // For us

    void helper_insert(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a'; // word - 'a' gives the index 0 for a 1 for b and so on
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }

        else
        {
            child = new TrieNode(word[0]); // creating a new object  if trienode and then
            root->children[index] = child; // connecting child to root ;
        }

        helper_insert(child, word.substr(1));
    }

    // for user

    void insert(string word)
    {
        helper_insert(root, word);
    }

    bool user_search(TrieNode *root, string word)
    {

        int index = word[0] - 'a'; // it gives us the index of that alphabet bcz all alphabet are ordered like 0/a, 1/b,2/c 3/d

        if (root->children[index] == NULL)
        {
            return false;
        }

        if (word.size() == 1)
        {
            return root->children[index]->isTerminal;
        }

        return user_search(root->children[index], word.substr(1));
    }

    bool search(string word)
    {
        return user_search(root, word);
    }

    void user_remove(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        // small calculation

        TrieNode *child;

        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }

        user_remove(child, word.substr(1));

        if (child->isTerminal == false) // it means no word is ending here now in loop we have to check whether whether the
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void remove(string word)
    {
        user_remove(root, word);
    }
};

int main()
{
    Trie t;
    t.insert("apple");
    t.insert("ball");
    t.insert("cat");
    t.insert("dog");

    cout << t.search("ball") << endl;
    t.remove("ball");
    cout << t.search("ball") << endl;

    return 0;
}