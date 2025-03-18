class Solution {
public:
    int getLargestOutlier(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        int totalSum = 0;
        for (int c : nums)
        {
            totalSum += c;
            mp[c]++;
        }

        int ans = INT_MIN;
        // Iterate over each element
        for (int i = 0; i < nums.size(); i++)
        {
            // Remove the current element from the total sum and update its count.
            totalSum -= nums[i];
            mp[nums[i]]--;

            // Only proceed if the remaining sum is even.
            if (totalSum % 2 == 0)
            {
                int K = totalSum / 2;
                // Check if K appears among the remaining numbers.
                if (mp[K] >= 1)
                {
                    ans = max(ans, nums[i]);
                }
            }
            
            // Restore the current element back.
            totalSum += nums[i];
            mp[nums[i]]++;
        }

        return ans;
    }
};
