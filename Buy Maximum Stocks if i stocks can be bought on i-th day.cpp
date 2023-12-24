"""
 Title     : Buy Maximum Stocks if i stocks can be bought on ith day
 Author    : Raksha Rane
 Solved On   : 24 Dec 2023
 Solved Using   : C++ (g++ 5.4)
 """
  
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        pair<int, int> arr[n];
        
        for (int i = 0; i < n; ++i) {
            arr[i] = make_pair(price[i], i + 1);
        }
        
        sort(arr, arr + n, [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int today = arr[i].first;
            int stocks = arr[i].second;
            
            int can_buy = min(stocks, k / today);
            res += can_buy;
            k -= today * can_buy;
        }
        
        return res;
    }
};


// Time Complexity  : O(nlogn)
// Space Complexity : O(n)
