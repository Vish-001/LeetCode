
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(root==nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        while(!q.empty())
        {
            vector<int>vec;
            int n=q.size();
            for(i=0;i<n;i++)
            {
                TreeNode*temp=q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
                vec.push_back(temp->val);
            }
         
            ans.push_back(vec);
        }
        return ans;
    }
};