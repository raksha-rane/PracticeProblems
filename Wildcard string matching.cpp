"""
 Platform          : GFG
 Title             : Wildcard string matching
 Author            : Raksha Rane
 Solved On         : 27 Dec 2023
 Solved Using      : C++ (g++ 5.4)
"""

  class Solution{
    public:
    bool match(string wild, string pattern)
    {
        if (wild.empty()) {
            return pattern.empty();
        }

        if (wild[0] == '*') {
            return match(wild.substr(1), pattern) || (!pattern.empty() && match(wild, pattern.substr(1)));
        } else if (wild[0] == '?') {
            return !pattern.empty() && match(wild.substr(1), pattern.substr(1));
        } else if (!pattern.empty() && wild[0] == pattern[0]) {
            return match(wild.substr(1), pattern.substr(1));
        }

        return false;
    }
};

