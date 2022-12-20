#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> height) {
        int n = height.size();
        int answer = 1;
        int i = 0;
        while(n > 2 && i < n-1){
            int distance = n-i-1;
            //cout << "i: " << i << "    n-1: " << n-1 << endl;
            //cout << "distance: " << distance << endl;
            if (height[i] < height[n-1]){    
                if (answer < height[i] * distance) answer = height[i] * distance;
                //cout << height[i] * distance << "   " << answer << endl;
                ++i;

            } 
            else {
                if (answer < height[n-1] * distance) answer = height[n-1] * distance;
                 //cout << height[n-1] * distance << "   " << answer << endl;
                --n;
            }
           
        }
        return answer;
    }
};

int main(){
    Solution a;
    cout << a.maxArea(vector<int> {1,8,6,2,5,4,8,3,7});
}