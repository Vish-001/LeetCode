class Solution {
public:
    int Func(int i, int preIndex, vector<int>& nums) 
    {
        if (i == nums.size()) 
        {
            return 0;
        }
        

        int exclude = Func(i + 1, preIndex, nums); 
        int include = 0;
        if (preIndex == -1 || nums[i] > nums[preIndex]) 
        {
            include = 1 + Func(i + 1, i, nums); 
        }

        return max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums)
     {
        int n = nums.size();
        return Func(0, -1, nums); 
    }
};
