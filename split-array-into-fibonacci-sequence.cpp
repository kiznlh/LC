#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int> splitIntoFibonacci(string num) {
        vector<int> answer;
        if (num[0] == 0) return answer;
        int n = num.length();
        int i = 1;
        while(i < n){
            int temp1 = atoi(num.substr(n-i,i).c_str());
            // int temp2 = atoi(num.substr(n-i-i,))
        }
    }
};