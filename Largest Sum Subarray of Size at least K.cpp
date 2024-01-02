"""
 Platform          : GFG
 Title             : Largest Sum Subarray of Size at least K
 Problem statement : Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.
 Author            : Raksha Rane
 Solved On         : 02 Jan 2024
 Solved Using      : C++ (g++ 5.4)
"""

class Solution{
  public:
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long int> maxSum(n, 0);

        maxSum[0] = a[0];
        for (long long int i = 1; i < n; ++i) {
            maxSum[i] = max(a[i], maxSum[i - 1] + a[i]);
        }

        long long int var = 0, ans = 0;
        for (long long int i = 0; i < k; ++i) {
            var += a[i];
        }
        ans = var;

        for (long long int i = k; i < n; ++i) {
            var = var + a[i] - a[i - k];
            ans = max({ans, var, var + maxSum[i - k]});
        }

        return ans;
    }
};

// Time Complexity  : O(n)
// Space Complexity : O(n)
