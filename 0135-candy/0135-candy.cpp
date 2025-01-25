class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int ans=0;
        int i=1;
        int n=ratings.size();
        while(i<ratings.size())
        {
            if(ratings[i]==ratings[i-1])
            {
                ans+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++;
                ans+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1])
            {
                ans+=down;
                down++;
                i++;
            }
            if(down>peak)
            {
                ans+=(down-peak);
            }
        }
        return ans+1;
    }
};