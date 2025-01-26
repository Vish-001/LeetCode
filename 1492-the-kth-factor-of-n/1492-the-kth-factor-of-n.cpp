class Solution {
public:
    int kthFactor(int n, int k) 
    {
        int u=k;
        for(int i=1;i<=n;i++)
        {
            if((n%i) == 0)
            {
                u--;
            }
            if(u==0)
            {
                return i;
            }
        }
        return -1;
    }
};