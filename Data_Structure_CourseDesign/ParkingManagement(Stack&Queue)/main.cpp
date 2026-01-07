#include<iostream>
#include<vector>
#include"Stack.hpp"
#include"Queue.hpp"
using namespace std;


struct car{
    char info; //A为到达，D为离去，E表示结束
    int arrive_time; //到达时间
    int depart_time; //离开时间
};

int main(){
    char c;
    int a,d;
    vector<car> cars;
    cars.reserve(20);
    while(1){
        cin>>c>>a>>d;
        if(c!='E') break;
        
    }
}