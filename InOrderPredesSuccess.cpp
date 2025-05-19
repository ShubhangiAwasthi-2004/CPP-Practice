// You are given root node of the BST and an integer key. You need to find the in-order 
// successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the 
// predecessor and the number just greater than the target is the successor. 

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* curr = root;
        
        // Find predecessor
        while (curr) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        
        curr = root;
        
        // Find successor
        while (curr) {
            if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        
        return {pre, suc};
    }
};
