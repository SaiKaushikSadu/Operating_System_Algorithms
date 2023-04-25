#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //MFT

    //Block
    int nb;
    cout<<"Enter the no of blocks"<<endl;
    cin>>nb;
    int block;
    cout<<"Enter the block size"<<endl;
    cin>>block;

    //Process
    int np;
    cout<<"Enter the no of processes"<<endl;
    cin>>np;
    int process[np];
    cout<<"Enter the process size"<<endl;
    for(int i=0;i<np;i++){
        cout<<"P["<<i<<"]";
        cin>>process[i];
    }

    int flag[nb];
    int alloc[nb];
    int fragment[nb];

    //Default
    for(int i=0;i<nb;i++){
        alloc[i]=-1;
        flag[i]=0;
        fragment[i]=-10;
    }

    //Logic
    for(int i=0;i<np;i++){
        for(int j=0;j<nb;j++){
            if(flag[j]==0 && block>=process[i]){
                alloc[j]=i;
                flag[j]=1;
                fragment[j]=block-process[i];
                break;
            }
        }
    }

    //Output
    cout<<"Block Size\tProcess No.\tProcess Size\tFragment"<<endl;
    for(int i=0;i<nb;i++){
        if(flag[i]==1){
            cout<<block<<"\t\t"<<alloc[i]<<"\t\t"<<process[alloc[i]]<<"\t\t"<<fragment[i]<<endl;
        }
        else{
            cout<<block<<"\t\t"<<"---------------------------------------------"<<endl;
        }
    }
    
    return 0;
}