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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return NULL;
        }

        //if curr finds p or q return curr
        if(root == p or root == q){
            return root;
        }

        //search in left and then in right part
        TreeNode* leftN = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightN = lowestCommonAncestor(root->right, p, q);

        //if p and q are in different subTree return root
        if(leftN != NULL and rightN != NULL){
            return root;
        }

        //if any of them(leftN or rightN) is not NULL return that node
        if(leftN != NULL){
            return leftN;
        }
        else if(rightN != NULL){
            return rightN;
        }
    }
};
