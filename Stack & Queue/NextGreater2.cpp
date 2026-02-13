#include <bits/stdc++.h>
using namespace std;
// Leetcode : 503. Next Greater Element II
//Approach : Using Stack to store the indices of the elements
//loop through the array twice to find the next greater element for each index.
//Time complexity : O(n) 
//Space complexity : O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        int n = nums.size();
        for(int i = 2*n -1;i>=0 ;i--){
            int idx = (i%n);
            while(!st.empty() && nums[st.top()] <= nums[idx]){
                st.pop();
            }
            //push only when we are in the first loop, i.e. when i<n
            if(i<n && !st.empty()){
                ans[i] = nums[st.top()];
            }
            st.push(idx);
        }
        return ans;

    }
};