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
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        //calculate left and right subtree heights
        int leftH = height(root->left);
        int rightH = height(root->right);
        
        return max(leftH, rightH) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }

        //find height of left and right child
        int leftH = height(root->left);
        int rightH = height(root->right);
        
        //check height difference
        if(abs(leftH - rightH) > 1){
            return false;
        }

        //check if the left and right child is also balanced
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
