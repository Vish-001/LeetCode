class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        int nums1=INT_MAX;
        int nums2=INT_MAX;
        for(auto c:nums)
        {
            if(c<nums1)
            {
                nums1=c;
            }
            else if(c>nums1 && c<nums2)
            {
                nums2=c;
            }
            else if(c>nums2)
            {
                return true;
            }
        }
        return false;
    }
};