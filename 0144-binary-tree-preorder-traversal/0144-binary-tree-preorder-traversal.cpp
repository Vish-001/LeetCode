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
    void Func(TreeNode*temp,vector<int>&ans)
    {
        if(temp==nullptr)
        {
            return;
        }
        int k=temp->val;
        ans.push_back(k);
        Func(temp->left,ans);
        Func(temp->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        Func(root,ans);
        return ans;
    }
};