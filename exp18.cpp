#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //FCFS Disk Scheduling
    int n;
    cout<<"Enter the no of processes: "<<endl;
    cin>>n;

    int process[n];
    cout<<"Enter the position of the process "<<endl;
    for(int i=0;i<n;i++){
        cin>>process[i];
    }

    int head;
    cout<<"Enter the position of the head "<<endl;
    cin>>head;

    int total=0;
    total=abs(head-process[0]);
    cout<<"STATUS OF HEAD"<<endl;
    for(int i=0;i<n-1;i++){
        cout<<"Head moved to "<<process[i]<<endl;
        total+=abs(process[i]-process[i+1]);
    }
    cout<<"Head moved to "<<process[n-1]<<endl;

    cout<<"The total head movement is "<<total<<endl;

    return 0;
}