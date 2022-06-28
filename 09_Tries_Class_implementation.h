class TrieNode
{
public:
    int data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;  // every time we have to insert a char of string
        children = new TrieNode *[26];

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal  = false;
    }
};