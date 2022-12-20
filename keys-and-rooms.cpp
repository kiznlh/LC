#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> check (n, false);
        check[0] = true;
        stack<int> st;
        int m = rooms[0].size();
        for (int j = 0; j < m; ++j){
            st.push(rooms[0][j]);
            check[rooms[0][j]] = true;
        }   
        while (!st.empty()){
            int temp = st.top();
            st.pop();
            m = rooms[temp].size();
            for (int j = 0; j < m ; ++j){
                if (!check[rooms[temp][j]]){
                    st.push(rooms[temp][j]);
                    check[rooms[temp][j]] = true;
                }
            }
        }
        if (check != vector<bool> (n, true)){ return false;}
        return true;
    }
};