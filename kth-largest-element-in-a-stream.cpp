#include <bits/stdc++.h>
using namespace std;

class KthLargest {
priority_queue<int,vector<int>,greater<int>> pq;
// min_heap data structure -> sorted in ascending order
    int sz;
    KthLargest(int k, vector<int>& nums) {

         sz = k;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        
    }
    
    int add(int val) {
        
       pq.push(val);
        while(pq.size()>sz){
            pq.pop();
        }
        return pq.top();
    }
};