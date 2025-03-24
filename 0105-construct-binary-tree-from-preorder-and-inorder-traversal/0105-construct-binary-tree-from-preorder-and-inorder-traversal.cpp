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
    TreeNode* Build(int &i,int start,int end,vector<int>&preorder,vector<int>&inorder,unordered_map<int,int>&mp)
    {
        if(start>end) return nullptr;
        if(i<0 || i>=preorder.size()) return nullptr;
        TreeNode*temp=new TreeNode(preorder[i]);
        int idx=mp[preorder[i]];
        i++;
        temp->left=Build(i,start,idx-1,preorder,inorder,mp);
        temp->right=Build(i,idx+1,end,preorder,inorder,mp);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.size()==0) return nullptr;
        unordered_map<int,int>mp;
        for(int i=0;i<preorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int i=0;
        return Build(i,0,preorder.size()-1,preorder,inorder,mp);
    }
};