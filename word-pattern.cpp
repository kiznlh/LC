#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char,string> key;
    stringstream streamS(s);
    int n = pattern.size();
    string temp;
    set<string> setW;
    vector<string> listW;
    while (streamS >> temp){
        listW.push_back(temp);
    }
    if (listW.size() != n) return false;
    for (int i = 0 ; i < pattern.size(); ++i){
        if (key.find(pattern[i]) == key.end()){
            if (setW.find(listW[i]) == setW.end())  {
                setW.insert(listW[i]);
                key.insert(pair<char,string> (pattern[i],listW[i]));
            }
            else return false;
        }
        else if (key[pattern[i]] != listW[i]) return false;
    }
    return true;
}

int main(){
    
}