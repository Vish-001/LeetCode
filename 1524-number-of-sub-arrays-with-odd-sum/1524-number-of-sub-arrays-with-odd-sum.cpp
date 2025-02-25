#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        const int MOD = 1e9+7;  
        int count=0;

        vector<int>Prefix(arr.size(),0);
        Prefix[0]=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            Prefix[i]=Prefix[i-1]+arr[i];
        }
        int odd=0;
        int even=1;

        for(int i=0;i<arr.size();i++)
        {
            if(Prefix[i]%2==0)
            {
                count=(count+odd)%MOD;
                even++;
            }
            else
            {
                count=(count+even)%MOD;
                odd++;
            }
        }

        return count;
    }
};
