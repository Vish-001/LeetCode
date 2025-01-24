class Solution {
public:
    static bool comp(vector<int>a,vector<int>b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),comp);
        int n=intervals.size();
        int cnt=1;
        int prev=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=intervals[prev][1])
            {
                cnt++;
                prev=i;
            }
        }
        return n-cnt;
    }
};