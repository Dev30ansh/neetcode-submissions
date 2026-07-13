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
private:
    int dfs(TreeNode* root, int maxVal){
        if(!root){
            return 0;
        }
        // good node
        int res = root->val >= maxVal ? 1 : 0;
        // compute max value to comapre with descendant
        maxVal = max(maxVal, root->val);

        // traverse left and right subtree
        res += dfs(root->left,maxVal);
        res += dfs(root->right,maxVal);

        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        return dfs(root, root->val);
    }
};
