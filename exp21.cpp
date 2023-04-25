#include<bits/stdc++.h>
using namespace std;

void look_right(int head,int process[],int n){
    int total=0;
    sort(process,process+n);

    int index;
    for(int i=0;i<n;i++){
        if(head==process[i]) index=i;
    }

    for(int i=index;i<n;i++){
        cout<<"Head moved to "<<process[i]<<endl;
    }

    for(int i=index-1;i>=0;i--){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    cout<<endl;

    total+=(process[n-1]-head)+(process[n-1]-process[0]);
    cout<<"The total head movement is "<<total<<endl;
}

void look_left(int head1,int process[],int n){
    int total=0;
    sort(process,process+n);

    int index;
    for(int i=0;i<n;i++){
        if(head1==process[i]) index=i;
    }

    for(int i=index;i>=0;i--){
        cout<<"Head moved to "<<process[i]<<endl;
    }

    for(int i=index+1;i<n;i++){
        cout<<"Head moved to "<<process[i]<<endl;
    }
    cout<<endl;

    total+=(head1-process[0])+(process[n-1]-process[0]);
    cout<<"The total head movement is "<<total<<endl;
}

int main(){
    
    //LOOK disk scheduling
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
    int head1=head;

    n++;
    process[n-1]=head;

    cout<<"-----------------"<<endl;
    cout<<"Towards RIGHT"<<endl;
    cout<<"-----------------"<<endl;
    look_right(head,process,n);

    cout<<endl;

    cout<<"-----------------"<<endl;
    cout<<"Towards LEFT"<<endl;
    cout<<"-----------------"<<endl;
    look_left(head1,process,n);

    return 0;
}