#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
        int max = pow(2,31)-1;
        int min = -pow(2,31);
        int ans = 0;
        bool check = false;
        if (x < 0){
            check = true;
            x = abs(x);
        }
        while (x > 0){
            if (ans*10 < min || ans*10 > max) return 0;
            ans = x % 10 + ans*10;
            x = x / 10;
        }
        if (check) ans = - ans;
        return ans;
    }
int main(){
    int x = 1534236469;
    cout << reverse(x);
}