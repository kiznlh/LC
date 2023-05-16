#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr){
    for (int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int traverse(vector<int> parent, string s, int k, int length){
    vector<int> temp;
    for (int i = 0; i < parent.size(); ++i){
        if (i != k && parent[i] == k && s[i] != s[k]){
            temp.push_back(i);
        }
    }
    //cout << k << " "; print(temp);
    if (temp.empty()) return length;
    else{
        vector<int> temp_length;

        for (int i = 0; i < temp.size();++i){
            temp_length.push_back(traverse(parent,s,temp[i],length+1));
        }
        //print(temp_length);
        return *max_element(temp_length.begin(),temp_length.end());
    }
}

int longestPath(vector<int>& parent, string s) {
    vector<int> temp_answer;
    for (int i = 0; i < parent.size(); ++i){
        temp_answer.push_back(traverse(parent,s,i,1));
    }
    for (int i = 1; i < parent.size(); ++i){
        if (s[parent[i]] != s[i] && temp_answer[i] +temp_answer[parent[i]] > temp_answer[i])
            temp_answer[i] += temp_answer[parent[i]];
    }
    print(temp_answer);
    return *max_element(temp_answer.begin(),temp_answer.end());
}

int main(){
    vector<int> parent {-1,0,0,0};
    string s = "aabc";
    longestPath(parent,s);
}