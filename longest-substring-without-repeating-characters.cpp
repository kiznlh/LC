#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 1) return 1;
        int i = 0;
        int size = 0;
        int largest = 0;
        string temp = "";
        int j = 0;   
        while (i < s.size()){
            //cout << "Char: " << s[i] << endl;
            if (temp.find(s[i]) == string::npos){
               // cout << i << "True" << endl ;
               ++size;
                temp += s[i];
               ++i;
              
               //cout << temp << endl;
            }
            else{
               if (largest < size) largest = size;
              // cout << i << "False" << endl;
                i = ++j;
                size = 0;
                temp.clear();
                temp = "";
            }
        }
            if (largest < size) largest = size;
        return largest;
    }
};
int main(){
    Solution a;
    cout << a.lengthOfLongestSubstring("abcabcbb");
}