// Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.

// Constraints:
// 1 ≤ preorder.size() ≤ 103
// 1 ≤ preorder[i] ≤ 103


class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
       vector<int> res;
        int idx = 0;
        findLeaves(preorder, idx, INT_MIN, INT_MAX, res);
        return res;
        
    }
    
    void findLeaves(vector<int>& preorder, int &idx, int minVal, int maxVal, vector<int>& res) {
        if (idx >= preorder.size()) return;

        int curr = preorder[idx];

        if (curr < minVal || curr > maxVal) return;

        idx++;
        int tempIdx = idx;

        // Left subtree
        findLeaves(preorder, idx, minVal, curr - 1, res);

        // Right subtree
        findLeaves(preorder, idx, curr + 1, maxVal, res);

        // If no child was processed, it's a leaf
        if (idx == tempIdx)
            res.push_back(curr);
    }
    
};
