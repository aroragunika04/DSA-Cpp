#include<bits/stdc++.h>
using namespace std;
//2696. Minimum String Length After Removing Substrings
//https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && s[i]=='B' && st.top()=='A'){
                st.pop();
            }
            else if(!st.empty() && s[i]=='D' && st.top()=='C'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        return st.size();
    }

};