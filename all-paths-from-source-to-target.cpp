#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dfs(vector<vector<int>> graph, int i, int n){
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        int n = graph.size();
        for (int i = 0 ; i < graph[0].size(); ++i){
            ans.push_back(vector<int> {0,graph[0][i]}); // 0,1  ; 0,2
        }
        for (int i = 0; i < ans.size(); ++i){
            vector<int> temp = ans[i];  // 0,1
            if (temp.back() != n - 1){
                int k = temp.back();
                for (int j = 0; j < graph[k].size(); ++j){
                    vector<int> temp2 = temp;
                    temp2.push_back(graph[k][j]);
                    ans.push_back(temp2);
                }
                ans.erase(ans.begin()+i);
                --i;
            }
        }
        return ans;
    }
};
void display(vector<int> arr){
    for (int i = 0 ; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<vector<int>> arr {{4,3,1},{3,2,4},{3},{4},{}};
    Solution a;
    vector<vector<int>> ans = a.allPathsSourceTarget(arr);
    for (int i = 0 ; i < ans.size(); ++i){display(ans[i]);}
}