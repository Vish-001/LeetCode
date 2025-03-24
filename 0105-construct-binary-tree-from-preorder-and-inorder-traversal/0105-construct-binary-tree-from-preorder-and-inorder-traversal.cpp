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
    TreeNode*Build(vector<int>&preorder,map<int,int>&mp,int sidx,int eidx,int &i)
    {
        if(sidx>eidx || i>=preorder.size())
        {
            return nullptr;
        }

        TreeNode*node=new TreeNode(preorder[i]);
        int idx=mp[preorder[i]];
        i++;
        node->left=Build(preorder,mp,sidx,idx-1,i);
        node->right=Build(preorder,mp,idx+1,eidx,i);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        map<int,int>mp;
        for(int i=0;i<preorder.size();i++)
        {
            mp[inorder[i]]=i;
        }
        int i=0;
        return Build(preorder,mp,0,preorder.size()-1,i);
    }
};