#include<bits/stdc++.h>
using namespace std;

void cscan_right(int head, int process[],int n,int maxtrack){
    int total=0;
    sort(process,process+n);    

    int index;
    for(int i=0;i<n;i++){
        if(head==process[i]) index=i;
    }

    for(int i=index;i<n;i++){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    cout<<"Head moved to "<<maxtrack<<endl;
    cout<<"Head moved to "<<0<<endl;
    for(int i=0;i<=index-1;i++){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    cout<<endl;

    total+=(maxtrack-head)+(maxtrack-0)+(process[index-1]-0);
    cout<<"The total head movement is "<<total<<endl;
}

void cscan_left(int head, int process[],int n,int maxtrack){
    int total=0;
    sort(process,process+n);    

    int index;
    for(int i=0;i<n;i++){
        if(head==process[i]) index=i;
    }

    for(int i=index;i>=0;i--){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    cout<<"Head moved to "<<0<<endl;
    cout<<"Head moved to "<<maxtrack<<endl;
    for(int i=n-1;i>=index+1;i--){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    cout<<endl;

    total+=(head-0)+(maxtrack-0)+(process[index+1]-0);
    cout<<"The total head movement is "<<total<<endl;
}

int main(){
    
    //C-SCAN Disk Scheduling
    int maxtrack;
    cout<<"Enter the maximum limit of disk "<<endl;
    cin>>maxtrack;
    maxtrack--;

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

    n++;
    process[n-1]=head;

    cout<<"-----------------"<<endl;
    cout<<"Towards RIGHT"<<endl;
    cout<<"-----------------"<<endl;
    cscan_right(head,process,n,maxtrack);

    cout<<endl;

    cout<<"-----------------"<<endl;
    cout<<"Towards LEFT"<<endl;
    cout<<"-----------------"<<endl;
    cscan_left(head,process,n,maxtrack);
    
    return 0;
}
