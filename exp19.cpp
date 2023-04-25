#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //SSTF Disk Scheduling
    int n;
    cout<<"Enter the no of processes: "<<endl;
    cin>>n;

    int head;
    cout<<"Enter the position of the head "<<endl;
    cin>>head;

    int process[n];
    cout<<"Enter the position of the process "<<endl;
    for(int i=0;i<n;i++){
        cin>>process[i];
    }

    int count=0;
    int total=0;

    cout<<"Head moved to "<<head<<endl;
    while(count!=n){
        int min=INT_MAX;
        int d,index;

        for(int i=0;i<n;i++){
            d=abs(process[i]-head);
            if(min>d){
                min=d;
                index=i;
            }
        }
        cout<<"Head moved to "<<process[index]<<endl;
        total+=min;
        head=process[index];
        process[index]=INT_MAX;
        count++;
    }

    cout<<"The total head movement is "<<total<<endl;
    
    return 0;
}