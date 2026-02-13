#include<bits/stdc++.h>
using namespace std;
//682. Baseball Game
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int res=0;
        for(int i=0;i<operations.size();i++){
            if(!st.empty() && operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                int a = st.top();
                st.push(2*a);
            }
            else if(operations[i]=="+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b);
                st.push(a);
                st.push(a+b);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        while(!st.empty()){
            res+= st.top();
            st.pop();
        }
        return res;
    }
};