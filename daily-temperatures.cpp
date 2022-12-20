#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        stack<int> st;
        for (int i = temperatures.size() - 1; i >= 0; --i){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            if (!st.empty())
                answer[i] = st.top() - i;
            st.push(i);
        }
        return answer;
    }
};
void display(vector<int> arr){
    for (int i = 0 ; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    Solution a;
    vector<int> arr = {73,74,75,71,69,72,76,73};
    display(a.dailyTemperatures(arr));
}