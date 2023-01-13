#include <bits/stdc++.h>
using namespace std;

class Circuit{
protected:
    double R;
public:
    Circuit(): R(0){}
    Circuit(double R): R(R){}
    virtual double calculate(){
        return R;
    }
    virtual ~Circuit(){
        cout << "DETELE CIRCUIT\n";
    };
    virtual Circuit* clone(){
        return new Circuit(*this);
    }

};

class ParralelCircuit:public Circuit{
private:
    vector<Circuit*> data;
public:
    ParralelCircuit(){}
    void addCircuit(Circuit* obj){
        data.push_back(obj->clone());
    }
    double calculate(){
        double ans = 0;
        for (Circuit* i: data){
            ans += 1/i->calculate();
        }
        return 1/ans;
    }
    ~ParralelCircuit(){
        for (Circuit*i:data){
            delete i;
        }
        cout << "DELETE PC\n";
    }
    Circuit* clone(){
        ParralelCircuit* newPC = new ParralelCircuit();
        for (int i = 0; i < data.size(); ++i){
            newPC->data.push_back(data[i]->clone());
        }
        return newPC;
    }
};
class SeriesCircuit:public Circuit{
private:
    vector<Circuit*> data;
public:
    //SeriesCircuit(){}
    void addCircuit(Circuit* obj){
        
    }
    double calculate(){
        double ans = 0;
        for (Circuit* i: data){
            ans +=i->calculate();
        }
        return ans;
    }
    ~SeriesCircuit(){
        for (Circuit*i:data){
            delete i;
        }
    }
};

int main(){
    Circuit* a = new Circuit(3);
    Circuit* b = new Circuit(4);
    Circuit* ab = new ParralelCircuit;
    dynamic_cast<ParralelCircuit*>(ab)->addCircuit(a);
    dynamic_cast<ParralelCircuit*>(ab)->addCircuit(b);
    cout << a->calculate() << endl;
    cout << b->calculate() << endl;
    cout << ab->calculate() << endl;
    cout << endl;
    dynamic_cast<ParralelCircuit*>(ab)->addCircuit(ab);
    cout << a->calculate() << endl;
    cout << b->calculate() << endl;
    cout << ab->calculate() << endl;
}