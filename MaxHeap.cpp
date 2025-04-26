//You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

//A binary tree is considered a max-heap if it satisfies the following conditions:

//Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
//Max-Heap Property: The value of each node is greater than or equal to the values of its children.

class Solution {
  public:
    bool isHeap(Node* tree) {
        if (!tree) return true;

        queue<Node*> q;
        q.push(tree);
        bool nullChildFound = false;

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            // Check left child
            if (curr->left) {
                if (nullChildFound || curr->data < curr->left->data)
                    return false;
                q.push(curr->left);
            } else {
                nullChildFound = true;
            }

            // Check right child
            if (curr->right) {
                if (nullChildFound || curr->data < curr->right->data)
                    return false;
                q.push(curr->right);
            } else {
                nullChildFound = true;
            }
        }

        return true;
    }
};
