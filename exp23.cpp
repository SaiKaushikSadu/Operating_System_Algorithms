#include<bits/stdc++.h>
using namespace std;

void clook_right(int head,int process[],int n){
    int total=0;
    sort(process,process+n);

    int index;
    for(int i=0;i<n;i++){
        if(head==process[i]) index=i;
    }

    for(int i=index;i<n;i++){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    
    for(int i=0;i<=index-1;i++){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    cout<<endl;

    total+=(process[n-1]-head)+(process[n-1]-process[0])+(process[index-1]-process[0]);
    cout<<"The total head movement is "<<total<<endl;
}

void clook_left(int head1,int process[],int n){
    int total=0;
    sort(process,process+n);

    int index;
    for(int i=0;i<n;i++){
        if(head1==process[i]) index=i;
    }

    for(int i=index;i>=0;i--){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    
    for(int i=n-1;i>=index+1;i--){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    cout<<endl;

    total+=(head1-process[0])+(process[n-1]-process[0])+(process[n-1]-process[index+1]);
    cout<<"The total head movement is "<<total<<endl;
}

int main(){
    
    //C-LOOK Disk Scheduling
    int n;
    cout<<"Enter the no of processes"<<endl;
    cin>>n;

    int process[n];
    cout<<"Enter the processes"<<endl;
    for(int i=0;i<n;i++){
        cin>>process[i];
    }
    
    int head;
    cout<<"Enter the head position"<<endl;
    cin>>head;

    n++;
    process[n-1]=head;
    int head1=head;

    cout<<"-----------------"<<endl;
    cout<<"Towards RIGHT"<<endl;
    cout<<"-----------------"<<endl;
    clook_right(head,process,n);

    cout<<endl;

    cout<<"-----------------"<<endl;
    cout<<"Towards LEFT"<<endl;
    cout<<"-----------------"<<endl;
    clook_left(head1,process,n);
    
    return 0;
}