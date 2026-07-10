/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        TreeNode* curr = root;

        while (true) {
            if (val > curr->val) {  // right me hoga
                if (!curr->right) {  // if right child null hai to right me dal do
                    curr->right = new TreeNode(val);
                    return root;
                }
                curr = curr->right;
            } 
            else {                  // left me hoga
                if (!curr->left) {  // if left child null hai to left me dal do
                    curr->left = new TreeNode(val);
                    return root;
                }
                curr = curr->left;
            }
        }
    }
};