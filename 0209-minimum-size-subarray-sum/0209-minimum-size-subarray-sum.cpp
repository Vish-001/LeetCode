class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int output = INT_MAX;
        int sum = nums[0], length = 0, i=0, j=0;
        //edge case with empty array or 2 ele array
        while(i<=j && j < nums.size())
        {
            if(sum >= target)
            {
                length = j-i+1;
                output = min(length, output);
                //we'll increment i, so remove num[i] from sum now to min the min length subarray
                sum -= nums[i];
                i++;
            }
            else //if(sum < target)
            {
                j++;
                if( j < nums.size())
                    sum += nums[j];
            }
        }

        if(nums.size() == 1)
        {
            if (nums[0] >= target)
                return nums.size();
        }

        return (output==INT_MAX)?0:output;
    }
};