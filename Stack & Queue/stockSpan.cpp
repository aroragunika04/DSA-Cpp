#include <bits/stdc++.h>
using namespace std;

//LeetCode 901: Online Stock Span
//Time Complexity : O(n)
//Space Complexity : O(n)

class StockSpanner {
public:
        int i = 0;
        stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans ;
       
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(!st.empty()){
            ans = i-st.top().second;
        }
        else{
            ans = i+1;
        }

        st.push({price,i});
        i++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */