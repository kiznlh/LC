#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        for (int i = 2; i < nums.size(); ++i){
            if ( i > 2) nums[i] += max(nums[i-2],nums[i-3]);
            else if (i == 2) nums[i] += nums[i-2];
        }
        return *max_element(nums.begin(),nums.end());
    }
};