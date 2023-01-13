#include <bits/stdc++.h>
using namespace std;

class Bot{
private:
    string name;
    float power;
public:
    Bot(){name = "", power = 0;};
    Bot(string name, float power){
        this->name = name;
        this->power = power;
    }
    string getName(){
        return name;
    }
    virtual float getPower(){
        return power;
    }
    virtual void setName(string name){
        this->name = name;
    }
    virtual void setPower(float power){
        this->power = power;
    }
    virtual Bot* clone(){
        return new Bot(*this);
    }
    virtual ~Bot(){};
};

class CombiBot: public Bot{
private:
    Bot* part1;
    Bot* part2;
public:
    CombiBot():Bot(){
        part1 = nullptr;
        part2 = nullptr;
    }
    CombiBot(Bot* a, Bot* b){

    }
    float getPower(){
        float ans = 0;
        
    }
};