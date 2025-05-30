// Given the root of a binary search tree and a number k, 
// find the greatest number in the binary search tree that is less than or equal to k.

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
          int res = -1;  // Use -1 or any sentinel value (depending on problem guarantees)

        while (root != nullptr) {
            if (root->data <= k) {
                res = root->data;      // Update result
                root = root->right;    // Try to find a larger valid value
            } else {
                root = root->left;     // Too large, go left
            }
        }

        return res;
        
    }
};
