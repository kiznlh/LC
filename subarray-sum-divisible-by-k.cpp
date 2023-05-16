#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k){
    int s = 0;
    int temp = 0;
    for (int i = 0 ; i < nums.size(); ++i){
        for (int j = i; j < nums.size(); ++j){
            temp+= nums[j];
            if (temp % k == 0) ++s;
        }
        temp = 0;
    }
    return s;
}

int main(){
    vector<int> nums{4,5,0,-2,-3,1};
    int k = 5;
    cout << subarraysDivByK(nums,k);
}