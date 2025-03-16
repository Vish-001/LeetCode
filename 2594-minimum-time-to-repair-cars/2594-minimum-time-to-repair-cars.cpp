class Solution {
public:

    bool Func(vector<int>& ranks, int cars,int Time)
    {
        for(auto c:ranks)
        {
            int ct=c;
            int cr=1;
            while(ct*(cr*cr)<Time)
            {
                cr++;
                cars--;
            }
        }
        if(cars>0) return false;
        return true;
    }

    long long repairCars(vector<int>& ranks, int cars) 
    {
        long long low=1;
        long long high=*min_element(ranks.begin(),ranks.end());
        high=high*cars*cars;

        while(low<=high)
        {
            long long mid=(low+high)/2;
            bool T=Func(ranks,cars,mid);
            if(T)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return high;
    }
};