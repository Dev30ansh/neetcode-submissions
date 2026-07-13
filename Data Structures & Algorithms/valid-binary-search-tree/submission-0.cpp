
class Solution {
private:
    // Check whether the subtree rooted at 'root' is valid,
    // where every node must be strictly between 'left' and 'right'.
    bool valid(TreeNode* root, int left, int right) {
        // An empty tree/subtree is always valid
        if (!root) {
            return true;
        }

        // Current node must be within the allowed range
        // BST rule: left < node->val < right
        if (!(left < root->val && root->val < right)) {
            return false;
        }

        // Left child must be in range: (left, root->val)
        // Right child must be in range: (root->val, right)
        return valid(root->left, left, root->val) &&
               valid(root->right, root->val, right);
    }

public:
    bool isValidBST(TreeNode* root) {
        // Start with the widest possible range
        return valid(root, INT_MIN, INT_MAX);
    }
};