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
    void Insert(TreeNode*root,int val)
    {
        TreeNode*node=new TreeNode(val);
        auto temp=root;
        while(temp)
        {
            if(temp->val>val)
            {
                if(temp->left==nullptr)
                {
                    temp->left=node;
                    return;
                }
                temp=temp->left;
            }
            else
            {
                if(temp->right==nullptr)
                {
                    temp->right=node;
                    return;
                }
                temp=temp->right;
            }
        }

    }
    TreeNode*root=nullptr;
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode*root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
        {
            Insert(root,preorder[i]);
        }
        
        return root;
    }
};