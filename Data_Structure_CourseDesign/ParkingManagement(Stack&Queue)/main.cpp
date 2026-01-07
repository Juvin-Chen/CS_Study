#include<iostream>
#include<unordered_map>
#include<vector>
#include"Car.h"
#include"Queue.h"
#include"Stack.h"
using namespace std;

unordered_map<int, int> park_map; //用来存储每个车辆对应的停车位置
vector<car> cars; 

int main(){
    char c;
    int a,b,i=0;
    Stack s1,s2;
    Queue q;
    InitStack(&s1); //s1用于表示停车场
    InitStack(&s2); //s2用于临时停放为给要离去的汽车让路而从停车场退出来的汽车
    InitQueue(&q);
    int queue_num=0;
    while(1){
        car car_one;
        cin>>c>>a>>b; 
        car_one.num=a;
        if(c=='A'){
            if(s1.top-s1.base!=s1.stacksize){
                car_one.arrive_time=b;
                park_map[a]=s1.top-s1.base+1;
                Push(&s1,car_one);
                cars.push_back(car_one);
                cout<<"车辆到达，停车场未满，车辆停在停车场从北往南第"<<park_map[a]<<"个位置\n";
            }else{
                EnQueue(&q,car_one);
                queue_num++;
                cout<<"车辆到达，停车场已满，车辆停在便道上第"<<queue_num<<"个位置\n";
            }
        }else if(c=='D'){
            int count=s1.top-s1.base-park_map[a];
            car e;
            while(count--){
                Pop(&s1,&e);
                Push(&s2,e);
            }
            while(s2.top!=s2.base){
                Pop(&s2,&e);
                Push(&s1,e);
            }
            for(auto& pair:park_map) pair.second-=1;
            cout<<"车辆离开，车辆在停车场的停车时长为"<<cars[a].depart_time-cars[a].depart_time<<"min";
            //将便道上的队头车辆入栈
            DeQueue(&q,&e);
            e.arrive_time=b;
            park_map[e.num]=s1.stacksize;
            Push(&s1,e);
            cars.push_back(e);
        }else{
            break;
        }
    }
    return 0;
}