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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==nullptr) return 0;
        int ans=0;
        queue<pair<TreeNode*,long>> q;
        q.push({root, 0});
        
        while(!q.empty())
        {
            int n=q.size();
            long first_pos = q.front().second;
            long last_pos = first_pos;
            
            for(int i=0; i<n; i++)
            {
                auto p=q.front();
                q.pop();
                TreeNode* node = p.first;
                long pos = p.second;
                last_pos = pos;
                
                long adjusted_pos = pos - first_pos;
                
                if(node->left)
                    q.push({node->left, 2*adjusted_pos});
                if(node->right)
                    q.push({node->right, 2*adjusted_pos + 1});
            }
            
            int current_width = last_pos - first_pos + 1;
            ans = max(ans, current_width);
        }
        
        return ans;
    }
};