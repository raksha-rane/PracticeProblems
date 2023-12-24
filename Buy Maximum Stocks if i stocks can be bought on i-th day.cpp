"""
 Platform  : GFG
 Title     : Buy Maximum Stocks if i stocks can be bought on ith day
 Problem statement : In a stock market, there is a product with its infinite stocks. 
 The stock prices are given for N days, where price[i] denotes the price of the stock on the ith day. 
 There is a rule that a customer can buy at most i stock on the ith day. 
 If the customer has an amount of k amount of money initially. 
 The task is to find out the maximum number of stocks a customer can buy. 
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


// Time Complexity      : O(nlogn)
// Space Complexity     : O(n)

// Algorithms used      : Greedy algorithm
// Data structures used : Array, Pair
// Functions used       : sort, min, make_pair
