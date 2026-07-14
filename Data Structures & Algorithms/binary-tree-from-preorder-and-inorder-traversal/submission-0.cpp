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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int &idx){
        if(start > end){
            return nullptr;
        }

        int size = inorder.size();
        //identify the root Value(1st index bcz preorder: root,left,right)
        int rootVal = preorder[idx];
        int i = start;

        //find rootVal in inorder
        for(; i < size; i++){
            if(inorder[i] == rootVal){
                break;
            }
        }
        //increment the root in preorder
        idx++;

        //create new node for rootValue and find its left and right child
        TreeNode* root = new TreeNode(rootVal);
        root->left = constructTree(preorder, inorder, start, i-1, idx);
        root->right = constructTree(preorder, inorder, i+1, end, idx);
        
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int idx = 0;

        return constructTree(preorder, inorder, 0, size-1, idx);
    }
};
