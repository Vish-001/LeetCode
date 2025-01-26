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
    int height(TreeNode*root)
    {
        if(root==nullptr) return 0;
        int L=height(root->left);
        int R=height(root->right);
        return max(L,R)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==0) return 0;

        int L=height(root->left);
        int R=height(root->right);
        
        return max(L+R,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        
    }
};