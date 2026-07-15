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
    int findMaxSum(TreeNode* root){
        if(!root){
            return 0;
        }

        int l = findMaxSum(root->left);
        int r = findMaxSum(root->right);

        // (1) : root ke niche he ans(maxsum) mil jaye ga
        int niche_answer_milgaya = l + r + root->val;

        // (2) : koi ek he acha hai (l,r)
        int ek_acha_hai = max(l,r) + root->val;

        // (3) : dono side kharab hai, bas root acha hai
        int root_acha = root->val;

        maxsum = max({maxsum, niche_answer_milgaya, ek_acha_hai, root_acha});

        return max(ek_acha_hai, root->val);
    }

public:
    int maxsum;
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;

        findMaxSum(root);

        return maxsum;
    }
};
