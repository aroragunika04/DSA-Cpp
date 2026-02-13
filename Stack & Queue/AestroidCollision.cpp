#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

// Leetcode : 735. Asteroid Collision
//Approach : Using Stack to store the asteroids and check for collision when we encounter a negative asteroid.
//Time complexity : O(n)
//Space complexity : O(n)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<0){
                while(!st.empty() &&st.top()>0&& abs(asteroids[i])>st.top()){
                    st.pop();
                }
                if(st.empty()||st.top()<0){
                    st.push(asteroids[i]);
                }
                else if(!st.empty() && abs(asteroids[i])==st.top()){
                st.pop();
                }
            
            }
            else{
                st.push(asteroids[i]);
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};