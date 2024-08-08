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
    int diametre = 0;
    int height(TreeNode* root){
        if(root==0)
           return 0;
        int l = height(root->left);
        int r = height(root->right);
        diametre = (diametre>(l+r)?diametre:(l+r));
        return 1 + (l>r?l:r);   
    }
    int diameterOfBinaryTree(TreeNode* root) {
      height(root);
      return diametre;  
    }
};