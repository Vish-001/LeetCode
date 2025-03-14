class Solution {
public:

    long long Sum(vector<int>& cand)
    {
        long long ans = 0;
        for (auto n : cand)
        {
            ans += n;
        }
        return ans;
    }

    bool Chk(vector<int>& cand, long long n, long long k)
    {
        long long ans = 0;
        for (auto u : cand)
        {
            ans += u / n;
        }
        return ans >= k;
    }

    int maximumCandies(std::vector<int>& candies, long long k)
    {
        long long ttl = Sum(candies);
        if (k > ttl) return 0;
        if (k == ttl) return 1;
        int result = 0;
        long long low = 1;
        long long high = *std::max_element(candies.begin(), candies.end());
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            bool t = Chk(candies, mid, k);
            if (t)
            {
                result = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return result;
    }
};