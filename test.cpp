#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Base{
public:
    T a;
    void setAge (const T& b){
        a = b;
    }
    T getAge(){return a;}
};

void print(vector<int> arr){
    for (auto i: arr){
        cout << i;
    }
    cout <<endl;
}


int main() {
    vector<int> arr = {1};
    arr.insert(arr.begin() , 2);
    print(arr);
}   
