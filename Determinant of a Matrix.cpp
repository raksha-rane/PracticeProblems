"""
 Platform          : GFG
 Title             : Determinant of a Matrix
 Problem statement : Given a square matrix of size n*n. The task is to find the determinant of this matrix.
 Author            : Raksha Rane
 Solved On         : 25 Dec 2023
 Solved Using      : C++ (g++ 5.4)
"""

class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        if (n == 1) {
            return matrix[0][0];
        }
        if (n == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
        }

        int deter = 0;
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> minorMatrix(n - 1, vector<int>(n - 1, 0));
            for (int j = 1; j < n; ++j) {
                for (int k = 0, l = 0; k < n; ++k) {
                    if (k != i) {
                        minorMatrix[j - 1][l++] = matrix[j][k];
                    }
                }
            }

            int cofac = matrix[0][i] * ((i % 2 == 0) ? 1 : -1);
            deter += cofac * determinantOfMatrix(minorMatrix, n - 1);
        }

        return deter;
    }
};



// Time Complexity: O(N^4)
// Space Complexity: O(N^2)

// Recursion used.
