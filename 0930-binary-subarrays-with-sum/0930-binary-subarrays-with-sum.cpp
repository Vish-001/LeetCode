class Solution {
public:
    int Func(vector<int>& nums, int goal) {
    int ans = 0;
    int l = 0, sum = 0;
    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        // Shrink the window until sum <= goal
        while(sum > goal && l <= r) {
            sum -= nums[l];
            l++;
        }
        ans += (r - l + 1);
    }
    return ans;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return Func(nums,goal)-Func(nums,goal-1);
    }
};