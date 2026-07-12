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
    vector<int> inorderTraversal(TreeNode* root) {
        //Morris Traversal
        vector<int> res;

        TreeNode* curr = root;

        while(curr != NULL){
            //if curr->left = null , store it and move to curr->right part
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            //curr->left != NULL, then: move to curr ka leftchild ka 
            // right most element and connect it's right pointer to curr.
            else{
                TreeNode* leftchild = curr->left;
                
                //right most node par jao
                while(leftchild->right != NULL){
                    leftchild = leftchild->right;
                }
                leftchild->right = curr;

                //remove connection of curr to its leftchild
                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
        }
        return res;
    }
};