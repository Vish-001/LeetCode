class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int>q;
        for(auto c:nums)
        {
            q.push(c);
        }
        k=k-1;
        while(k>0)
        {
            q.pop();
            k--;
        }
        return q.top();
    }
};