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
    bool Func(TreeNode*L1,TreeNode*R1)
    {
        if(R1==nullptr && L1==nullptr) return true;
        if(R1==nullptr || L1==nullptr || L1->val!=R1->val) return false;
        bool L=Func(L1->right,R1->left);
        bool R=Func(L1->left,R1->right);

        return L && R;
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(root==nullptr) return true;

        return Func(root->left,root->right);
    }
};