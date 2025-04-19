//Given an array arr[] of non-negative integers of size n. Find the maximum possible XOR between two numbers present in the array.

//Examples:

//Input: arr[] = [25, 10, 2, 8, 5, 3]
//Output: 28
//Explanation: The maximum possible XOR is 5 ^ 25 = 28.

class TrieNode {
public:
    TrieNode* child[2];
    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Solution {
public:
    void insert(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new TrieNode();
            }
            node = node->child[bit];
        }
    }

    int findMaxXOR(TrieNode* root, int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int toggledBit = 1 - bit;
            if (node->child[toggledBit]) {
                maxXor |= (1 << i);
                node = node->child[toggledBit];
            } else {
                node = node->child[bit];
            }
        }
        return maxXor;
    }

    int maxXor(vector<int> &arr) {
        TrieNode* root = new TrieNode();
        int maxResult = 0;

        insert(root, arr[0]);

        for (int i = 1; i < arr.size(); ++i) {
            maxResult = max(maxResult, findMaxXOR(root, arr[i]));
            insert(root, arr[i]);
        }

        return maxResult;
    }
};
