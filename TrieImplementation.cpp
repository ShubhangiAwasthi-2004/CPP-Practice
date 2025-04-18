//Implement Trie class and complete insert(), search() and isPrefix() function for the following queries :

//Type 1 : (1, word), calls insert(word) function and insert word in the Trie
//Type 2 : (2, word), calls search(word) function and check whether word exists in Trie or not.
//Type 3 : (3, word), calls isPrefix(word) function and check whether word exists as a prefix of any string in Trie or not.

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEndOfWord;
    }

    bool isPrefix(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return true;
    }
};
