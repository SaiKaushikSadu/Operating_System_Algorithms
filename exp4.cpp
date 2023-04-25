#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //Round Robin
    int i,n,time,remain,flag=0,time_quantum;
    float avg_wait=0;
    float avg_turn=0;

    int arrival[10];
    int burst[10];
    int rem[10];

    cout<<"Enter the no of processes"<<endl;
    cin>>n;

    remain=n;
    cout<<"Enter arrival time and burst time of each process"<<endl;
    for(i=0;i<n;i++){
        cout<<"P["<<i+1<<"]"<<endl;
        cin>>arrival[i];
        cin>>burst[i];
        rem[i]=burst[i];
    }

    cout<<"Enter the time quantum"<<endl;
    cin>>time_quantum;

    cout<<"Process\t\tWait time\tTurnaround time"<<endl;
    for(time=0,i=0;remain!=0;){
        if(rem[i]<=time_quantum && rem[i]>0){
            time+=rem[i];
            rem[i]=0;
            flag=1;
        }
        else if(rem[i]>0){
            time+=time_quantum;
            rem[i]-=time_quantum;
        }
        if(rem[i]==0 && flag==1){
            remain--;
            cout<<"P["<<i+1<<"]\t\t"<<time-arrival[i]-burst[i]<<"\t\t"<<time-arrival[i]<<endl;
            avg_wait+=time-arrival[i]-burst[i];
            avg_turn+=time-arrival[i];
            flag=0;
        }
        if(i==n-1){
            i=0;
        }
        else if(arrival[i+1]<=time){
            i++;
        }
        else{
            i=0;
        }
    }

    cout<<"Average waiting time: "<<avg_wait/n<<endl;
    cout<<"Average turn around time: "<<avg_turn/n<<endl;

    return 0;
}