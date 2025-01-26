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
    int maxi=INT_MIN;


    int Func(TreeNode*root)
    {
        if(root==nullptr) return 0;
        int L=max(0,Func(root->left));
        int R=max(0,Func(root->right));
        maxi=max(maxi,L+root->val+R);

        return max(L,R)+root->val;
    }


    int maxPathSum(TreeNode* root) 
    {
        if(root==nullptr) return 0;
        Func(root);
        return maxi;
    }
};