class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int>ans(nums.size(),-1);
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            st.push(nums[i]);
        }
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};