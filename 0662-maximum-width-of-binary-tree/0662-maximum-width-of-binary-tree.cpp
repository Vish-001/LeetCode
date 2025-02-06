
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            int first,last;
            for(int i=0;i<n;i++)
            {
                auto P=q.front();
                q.pop();
                auto node=P.first;
                long curr=P.second;
                if(i==0) first=curr;
                if(i==n-1) last=curr;
                if(node->left)
                {
                    q.push({node->left,(2*curr)+1});
                }
                if(node->right)
                {
                    q.push({node->right,(2*curr)+2});
                }
            }
            ans=max(ans,((last-first)+1));
        }
        return ans;
    }
};