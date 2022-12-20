#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 1) return s;
        int i = 0;
        int size = 0;
        int largest = 0;

        string temp2 = "";
        int j = 0; 
        while (i < s.size()){
            string temp = temp2;
            temp.reserve();
            if (temp == temp2){
               // cout << i << "True" << endl ;
               ++size;
                temp2 += s[i];
               ++i;
              
               //cout << temp << endl;
            }
            else{
               if (largest < size) largest = size;
              // cout << i << "False" << endl;
                i = ++j;
                size = 0;
                temp2.clear();
            }
        }
            if (largest < size) largest = size;
        return temp2;
    }
};