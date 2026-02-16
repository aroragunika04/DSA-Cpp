#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//456. 132 Pattern
//Time Complexity: O(n)
//Space Complexity: O(n)

//Approach: Traverse array from right to left and maintain a stack of elements which are greater than the current element. 
//If the current element is less than the middle element, then we have found a 132 pattern. Otherwise, we pop elements from the stack until we find an element which is greater than the current element and update the middle element.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack <int> st;
        int middle = INT_MIN;
        for(int i= nums.size()-1; i>=0 ;i--){
            while(!st.empty() && nums[i]>st.top()){
                middle = st.top();
                st.pop();
            }
            if(nums[i]<middle){
                return true;
            }
            st.push(nums[i]);
        }

        return false;
        
    }
};