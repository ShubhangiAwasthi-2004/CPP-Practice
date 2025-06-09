// You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

// Your task is to determine whether the BST contains a dead end.

// Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

// Examples:

// Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

// Output: true
// Explanation: Node 1 is a Dead End in the given BST.
// Input: root[] = [8, 7, 10, 2, N, 9, 13]

// Output: true
// Explanation: Node 9 is a Dead End in the given BST.
// Constraints:
// 1 ≤ number of nodes ≤ 3000
// 1 ≤ node->data ≤ 105


/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
     bool checkDeadEnd(Node* root, int minVal, int maxVal) {
        if (!root) return false;

        // If this is a leaf and no room to insert any new node
        if (minVal == maxVal)
            return true;

        // Check left and right subtrees
        return checkDeadEnd(root->left, minVal, root->data - 1) ||
               checkDeadEnd(root->right, root->data + 1, maxVal);
    }

    bool isDeadEnd(Node *root) {
        return checkDeadEnd(root, 1, INT_MAX);
    }
};
