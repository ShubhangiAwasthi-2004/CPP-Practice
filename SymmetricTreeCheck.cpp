// Given the root of a binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.
// A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

// Examples:
// Input: root[] = [1, 2, 2, 3, 4, 4, 3]
// Output: True
// Explanation: As the left and right half of the above tree is mirror image, tree is symmetric.

// Input: root[] = [1, 2, 2, N, 3, N, 3]
// Output: False
// Explanation:  As the left and right half of the above tree is not the mirror image, tree is not symmetric. 

// Constraints:
// 1  ≤ number of nodes ≤ 2000

/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
         bool isMirror(Node* t1, Node* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return (t1->data == t2->data) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(Node* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};
