#include<bits/stdc++.h>
using namespace std;
//1475 : Prices with special Discount
//https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/

//uses next smaller element in right;
class Solution {
public:
    vector<int> finalPrices(vector<int>& arr) {
        stack<int> st;
        vector<int> res = arr;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i] = arr[i]-st.top();
            }
            st.push(arr[i]);
        }
        return res;
        
    }
};