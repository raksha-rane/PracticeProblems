"""
 Platform          : GFG
 Title             : Check if a string is repetition of its substring of k-length
 Problem statement : Given a string s, check if it is possible to convert it into a string that is the repetition of a substring of length k. 
                     Conversion has to be done by following the steps mentioned below only once:
                     Select two indices i and j (zero-based indexing, i could be equal to j), such that i and j are divisible by k.
                     Select substrings of length k starting from indices i and j.
                     Replace substring starting at index i with substring starting at index j within the string.
 Author            : Raksha Rane
 Solved On         : 29 Dec 2023
 Solved Using      : C++ (g++ 5.4)
"""
  
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if (n % k != 0) return 0;

        unordered_map<string, int> substrCount;
        for (int i = 0; i < n; i += k) {
            string substr = s.substr(i, k);
            substrCount[substr]++;
        }

        int maxi = 0;
        for (const auto& entry : substrCount) {
            maxi = max(maxi, entry.second);
        }

        return (maxi < (n / k) - 1) ? 0 : 1;
	}
};

// Time Complexity: O(n).
// Space Complexity: O(n).
