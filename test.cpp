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




int main() {
    Base<int> ab;
    ab.setAge(3);
    cout << ab.getAge();
}   
