class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        stack<int>st;
        st.push(0);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[st.top()])
            {
                st.push(i);
            }
        }

        int ans=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty() && nums[i]>=nums[st.top()])
            {
                ans=max(ans,i-st.top());
                st.pop();
            }
        }
        return ans;
    }
};