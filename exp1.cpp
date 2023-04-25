#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //FCFS 
    int n;
    int burst[10];
    int wait[10];
    int turn[10];
    float avg_wait=0;
    float avg_turn=0;

    cout<<"Enter the no. of processes:"<<endl;
    cin>>n;

    cout<<"Enter the burst time for each process"<<endl;
    for(int i=0;i<n;i++){
        cout<<"p["<<i+1<<"]"<<endl;
        cin>>burst[i];
    }

    wait[0]=0;
    for(int i=1;i<n;i++){
        wait[i]=wait[i-1]+burst[i-1];
    }

    for(int i=0;i<n;i++){
        turn[i]=burst[i]+wait[i];
        avg_wait+=wait[i];
        avg_turn+=turn[i];
    }

    cout<<"Process\t\tBurst Time\tWait time\tTurn around time"<<endl;
    for(int i=0;i<n;i++){
        cout<<"p["<<i+1<<"]\t\t"<<burst[i]<<"\t\t"<<wait[i]<<"\t\t"<<turn[i]<<endl;
    }

    avg_wait/=n;
    avg_turn/=n;

    cout<<"average waiting time:"<<avg_wait<<endl;
    cout<<"average turn around time:"<<avg_turn<<endl;
    
    
    return 0;
}