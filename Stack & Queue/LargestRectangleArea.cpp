#include <bits/stdc++.h>
using namespace std;

//84. Largest Rectangle in Histogram
//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution {
public:
    vector<int> prev(vector<int> arr){
        stack<int> st;
        vector<int> ans(arr.size(),-1);
        for(int i = 0;i<arr.size();i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> next(vector<int> arr){
        stack<int> st;
        vector<int> ans(arr.size(),arr.size());
        for(int i = arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextEl = next(heights);
        vector<int> prevEl = prev(heights);
        int w = 0, ans = 0;
        for(int i = 0; i<heights.size();i++){
                w = nextEl[i] - prevEl[i] -1;
            ans = max(ans, w*heights[i]);
        }
        return ans;
    }
};