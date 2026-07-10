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
    TreeNode* minValueNode(TreeNode* root){
        TreeNode* curr = root;
        while(curr and curr->left){
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return NULL;
        }

        if (key > root->val) {
           root->right = deleteNode (root->right, key);
        } 
        else if (key < root->val) {
            root->left = deleteNode (root->left, key);
        }
        else{
            //node to remove have 0 child or 1 child
            if(!root->left){
                return root->right;
            }
            else if(!root->right){
                return root->left;
            }
            //node to remove have 2 child
            else{
                TreeNode* minNode  = minValueNode(root->right);
                root->val = minNode->val;
                root->right = deleteNode(root->right,minNode->val);
            }
        }
        return root;
    }
};