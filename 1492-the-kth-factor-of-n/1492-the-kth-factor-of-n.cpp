class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;

        // Iterate only up to √n to find all smaller factors
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                factors.push_back(i); // Add the smaller factor

                // Add the corresponding larger factor if it's different
                if (i != n / i) {
                    factors.push_back(n / i);
                }
            }
        }

        // Sort factors to ensure they're in ascending order
        sort(factors.begin(), factors.end());

        // Check if k factors exist
        if (k > factors.size()) {
            return -1; // Not enough factors
        }

        return factors[k - 1]; // Return the kth factor
    }
};
