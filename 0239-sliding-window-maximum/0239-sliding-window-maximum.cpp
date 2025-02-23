class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            while(!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }

            while(!dq.empty() && dq.front() < i-k+1)
            {
                dq.pop_front();
            }

            dq.push_back(i);

            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};