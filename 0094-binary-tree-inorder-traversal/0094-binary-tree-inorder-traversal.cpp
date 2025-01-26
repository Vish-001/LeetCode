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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        if(root==nullptr) return ans;
        stack<TreeNode*>st;
        auto node=root;
        while(!st.empty() || node!=nullptr)
        {
            while(node!=nullptr)
            {
                st.push(node);
                node=node->left;
            }
            node=st.top();
            ans.push_back(node->val);
            st.pop();
            node=node->right;
        }
        return ans;
    }
};