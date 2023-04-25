#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //Preemptive Priority
    int n;
    int burst[10];
    int pri[10];
    int wait[10];
    int turn[10];
    int p[10];
    float avg_wait;
    float avg_turn;

    cout<<"Enter the no of processes"<<endl;
    cin>>n;
    cout<<"Enter the burst time and the priority"<<endl;
    for(int i=0;i<n;i++){
        cout<<"P["<<i+1<<"]"<<endl;
        cin>>burst[i];
        cin>>pri[i];
        p[i]=i+1;
    }

    int pos;
    int temp;
    for(int i=0;i<n;i++){
        pos=i;
        for(int j=i+1;j<n;j++){
            if(pri[j]<pri[pos]){
                pos=j;
            }
        }
        temp=pri[i];
        pri[i]=pri[pos];
        pri[pos]=temp;

        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wait[0]=0;
    for(int i=1;i<n;i++){
        wait[i]=wait[i-1]+burst[i-1];
    }

    for(int i=0;i<n;i++){
        turn[i]=wait[i]+burst[i];
        avg_turn+=turn[i];
        avg_wait+=wait[i];
    }

    cout<<"Process\t\tBurst Time\tWait time\tTurn around time"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i]<<"\t\t"<<burst[i]<<"\t\t"<<wait[i]<<"\t\t"<<turn[i]<<endl;
    }

    avg_wait/=n;
    avg_turn/=n;

    cout<<"average waiting time:"<<avg_wait<<endl;
    cout<<"average turn around time:"<<avg_turn<<endl;
    
    return 0;
}