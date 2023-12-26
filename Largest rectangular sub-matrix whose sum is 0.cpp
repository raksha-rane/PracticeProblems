"""
 Platform          : GFG
 Title             : Largest rectangular sub-matrix whose sum is 0.
 Problem statement : Given a matrix mat[][] of size N x M. The task is to find the largest rectangular sub-matrix by area whose sum is 0.
                     If there are multiple solutions return the rectangle which starts from minimum column index. 
                     If you still have multiple solutions return the one having greatest row number. 
                     If no such matrix is present return a zero (0) size matrix.
 Author            : Raksha Rane
 Solved On         : 26 Dec 2023
 Solved Using      : C++ (g++ 5.4)
"""

class Solution {
public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();

        int left = 0, right = 0, up = 0, down = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> arr(m, 0);

            for (int j = i; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    arr[k] += a[k][j];
                }

                unordered_map<int, int> sum_map;
                int l = 0, r = 0, curr_sum = 0;

                for (int k = 0; k < m; ++k) {
                    curr_sum += arr[k];
                    if (curr_sum == 0) {
                        l = 0;
                        r = k + 1;
                    } else if (sum_map.find(curr_sum) != sum_map.end()) {
                        int new_l = sum_map[curr_sum] + 1;
                        int new_r = k + 1;
                        if (new_r - new_l > r - l) {
                            l = new_l;
                            r = new_r;
                        }
                    } else {
                        sum_map[curr_sum] = k;
                    }
                }

                if ((j - i + 1) * (r - l) > (right - left) * (down - up)) {
                    up = l;
                    down = r;
                    left = i;
                    right = j + 1;
                }
            }
        }
        vector<vector<int>> result(down - up, vector<int>(right - left, 0));

        for (int i = up; i < down; ++i) {
            for (int j = left; j < right; ++j) {
                result[i - up][j - left] = a[i][j];
            }
        }

        return result;
    }
};

// Time Complexity : O(n*m*m)
// Space Complexity : O(n*m)
