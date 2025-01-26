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
    int height(TreeNode*temp)
    {
        if(temp==nullptr) return 0;
        int L=height(temp->left);
        int R=height(temp->right);
        if(L>R) return L+1;
        return R+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==nullptr) return 0;
        int d1=height(root->left)+height(root->right);
        int d2=diameterOfBinaryTree(root->left);
        int d3=diameterOfBinaryTree(root->right);

        return max({d1, d2, d3});
    }
};