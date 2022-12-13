#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void display(vector<vector<int>> matrix){
        for (int i = 0; i < matrix.size();++i){
            for (int j = 0;j < matrix.size(); ++j){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       //display(matrix);
       for(int i=1;i<n;i++){
           for(int j=0;j<n;j++){
               matrix[i][j]+=min({matrix[i-1][j],matrix[i-1][max(0,j-1)],matrix[i-1][min(n-1,j+1)]});
           }
           //display(matrix);
           
       } 
       return *min_element(matrix[n-1].begin(),matrix[n-1].end());
    }

};
int main(){
    vector<int> a;
    for (int i = 0; i < 4; ++i){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    vector<int> b;
    for (int i = 0; i < 4; ++i){
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    vector<int> c;
    for (int i = 0; i < 4; ++i){
        int temp;
        cin >> temp;
        c.push_back(temp);
    }
    vector<int> d;
    for (int i = 0; i < 4; ++i){
        int temp;
        cin >> temp;
        d.push_back(temp);
    }
    vector<vector<int>> test;
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    test.push_back(d);
    Solution sol;
    cout << sol.minFallingPathSum(test);
}

