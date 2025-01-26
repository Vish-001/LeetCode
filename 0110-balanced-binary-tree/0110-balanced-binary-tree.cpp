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

    bool isBalanced(TreeNode* root) 
    {
        if(root==nullptr) return true;
        int L=height(root->left);
        int R=height(root->right);

        if(L-R>1) return false;
        if(R-L>1) return false;
        
        bool l=isBalanced(root->left);
        bool r=isBalanced(root->right);

        if(l==false || r==false) return false;
        return true;
    }
};