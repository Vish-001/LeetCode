class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int lsum=0;
        int rsum=0;
        for(int i=0;i<k;i++)
        {
            lsum+=cardPoints[i];
        }
        int ans=lsum;
        for(int i=0;i<k;i++)
        {
            lsum-=cardPoints[k-(i+1)];
            rsum+=cardPoints[cardPoints.size()-1-i];
            ans=max(ans,(lsum+rsum));
        }
        return ans;
    }
};