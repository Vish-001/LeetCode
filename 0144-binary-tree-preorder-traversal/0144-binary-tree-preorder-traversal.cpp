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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        if(root==nullptr) return ans;

        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            auto Node=st.top();
            st.pop();
            ans.push_back(Node->val);
            if(Node->right) st.push(Node->right);
            if(Node->left) st.push(Node->left);
        }
        return ans;
    }
};