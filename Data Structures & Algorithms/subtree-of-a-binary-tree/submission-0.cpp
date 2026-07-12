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
//helper function
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p and !q){
            return true;
        }

        // if p and q are same check for left and right child
        if(p and q and p->val == q->val){
            return (isSameTree(p->left,q->left) and 
                    isSameTree(p->right,q->right));
    
        }
        
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //if subRoot is null
        if(!subRoot){
            return true;
        }
        //if root is null
        if(!root){
            return false;
        }

        if(isSameTree(root, subRoot)){
            return true;
        }
        else{
            //check if subRoot is sub part of root->left part or root->left part
            return (isSubtree(root->left, subRoot) or 
                    isSubtree(root->right, subRoot));
        }
    }
};
