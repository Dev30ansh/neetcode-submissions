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
    int solve(TreeNode* root, int &result){
        if(!root){
            return 0;
        }

        //left me se no. of edges nikalo
        int left = solve(root->left, result);
        //right me se no. of edges nikalo
        int right = solve(root->right, result);

        //store result for every nodes
        result = max(result, left+right);

        //return the (max of left and right + 1 ) to its parent node so 
        //it knows how many edges are there in left or right child
        return (max(left, right)+1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int result = INT_MIN;

        if(!root){
            return 0;
        }
        solve(root, result);
        return result;
    }
};
