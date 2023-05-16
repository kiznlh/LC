#include <bits/stdc++.h>
using namespace std;
//ko cần loop finding, đề bài yêu cầu sub array tức là 1 đoạn trong array ví dụ 1,2,3,4 thì subarray là 1,2,3; 2,3,4; 3,4,1;
void loopFinding(vector<int>& nums){
    if (nums.size() == 0) return;
    int slow = 0;
    int fast = 1;
    int temp;
    while (true){
        ++slow;
        fast += 2;
        if (slow >= nums.size()) slow -= nums.size();
        if (fast >= nums.size()) fast -= nums.size();
        //cout << "Slow: " << slow << ", nums[slow]: " << nums[slow] << endl;
        //cout << "Fast: " << fast << ", nums[fast]: " << nums[fast] << endl;
        if (nums[slow] == nums[fast]){
            temp = nums[slow];
            break;
        }
    }
    if (slow != nums.size()){
        while (nums[0] != temp){
            nums.erase(nums.begin());
        }
    }
}

int maxSubarraySumCircular(vector<int>& A) {
    int total_sum=0,curr_sum1=0,curr_sum2=0,mxsum_subary=INT_MIN,minsum_subary=INT_MAX;   
    for(auto i:A)
    {
        total_sum+=i; curr_sum1+=i; curr_sum2+=i;
        mxsum_subary=max(mxsum_subary,curr_sum1);
        if(curr_sum1<0) curr_sum1=0;
        minsum_subary=min(curr_sum2,minsum_subary);
        if(curr_sum2>0) curr_sum2=0;
    }
    return (total_sum==minsum_subary)?mxsum_subary:max(mxsum_subary,total_sum-minsum_subary);  
}

int main(){
    vector<int> nums {1,-2,3,-2};
    int i = maxSubarraySumCircular(nums);
    cout << "I = " << i;
}