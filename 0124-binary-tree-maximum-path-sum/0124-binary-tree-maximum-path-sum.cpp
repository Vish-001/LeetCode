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
    int Height(TreeNode*temp,int &maxi)
    {
        if(temp==nullptr) return 0;
        int Lh=max(0,Height(temp->left,maxi));
        int Rh=max(0,Height(temp->right,maxi));

        maxi=max(Lh+Rh+temp->val,maxi);

        return  max(Lh,Rh)+temp->val;
    }
    int maxPathSum(TreeNode* root) 
    {
        if(root==nullptr) return 0;
        int maxi=INT_MIN;
        int Ls=Height(root->left,maxi);
        int Rs=Height(root->right,maxi);

        int maxi2=max(Ls+root->val,Rs+root->val);
        maxi2=max(maxi2,Ls+Rs+root->val);
        maxi2=max(maxi2,root->val);
        return max(maxi,maxi2);
    }
};