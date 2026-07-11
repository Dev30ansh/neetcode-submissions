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
    vector<int> res;

    void inorder(TreeNode* root){
        if(!root){
            return;
        }

        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        //inorder traversal of BST is sorted
        inorder(root);
        // return (k-1)th index as it is 1-indexed
        return res[k - 1];
    }
};
