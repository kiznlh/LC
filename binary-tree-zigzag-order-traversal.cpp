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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        if (!root) return ans;
        que.push(root);
        int level = 0;
        while (!que.empty()){
            vector<int> temp;
            int size = que.size();
            for (int i = 0; i < size; ++i){
                TreeNode* pTemp = que.front();
                que.pop();
                if (level == 0){
                    temp.push_back(pTemp->val);
                }
                else{
                    temp.insert(temp.begin(),pTemp->val);
                }
                if (pTemp->left) que.push(pTemp->left);
                if (pTemp->right) que.push(pTemp->right);
            }
            level = !level;
            ans.push_back(temp);
        }
        return ans;
    }
};