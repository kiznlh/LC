#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
      vector<long long int> ans;
    long long int dfs(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        
        long long int res=dfs(root->left)+root->val+dfs(root->right);
        
        ans.push_back(res);
        return res;    
        
    }
    int maxProduct(TreeNode* root) {
        
        dfs(root);
        
        long long int totalSum=ans[ans.size()-1];
        int mod=pow(10,9)+7;
        
        long long int mx=0;
        
        for(int i=0;i<ans.size();i++){
            long long r=(long long )(totalSum-ans[i]) ;
            long long res=(long long )ans[i]*r;
            mx=max(mx,res);
        }
        
        return mx%mod;
    }
};
int main(){
    
}