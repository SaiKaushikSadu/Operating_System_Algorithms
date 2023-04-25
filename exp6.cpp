#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //Best fit

    //Block
    int block[100];
    int nb;
    cout<<"Enter the no of Blocks"<<endl;
    cin>>nb;

    cout<<"Enter the size of Blocks: "<<endl;
    for(int i=0;i<nb;i++){
        cout<<"Block [ "<<i<<" ] ";
        cin>>block[i];
    }
    
    //Processes
    int process[100];
    int np;
    cout<<"Enter the no of Processes"<<endl;
    cin>>np;

    cout<<"Enter the size of Processes: "<<endl;
    for(int i=0;i<np;i++){
        cout<<"Process [ "<<i<<" ] ";
        cin>>process[i];
    }

    int alloc[nb];
    int flag[nb];
    int fragment[nb];

    //Default
    for(int i=0;i<nb;i++){
        alloc[i]=-1;
        flag[i]=0;
        fragment[i]=-10;
    }

    //Logic
    int j;
    for(int i=0;i<np;i++){
        int smallest=-1;
        for(j=0;j<nb;j++){
            if(flag[j]==0 && block[j]>=process[i]){
                smallest=j;
                break;
            }
        }
        for(;j<nb;j++){
            if(flag[j]==0 && block[j]>=process[i] && block[j]<block[smallest]){
                smallest=j;
            }
        }

        if(smallest!=-1){
            alloc[smallest]=i;
            flag[smallest]=1;
            fragment[smallest]=block[smallest]-process[i];
        }
    }

    //Output
    cout<<"Block Size\tProcess No.\tProcess Size\tFragment"<<endl;
    for(int i=0;i<nb;i++){
        if(flag[i]==1){
            cout<<block[i]<<"\t\t"<<alloc[i]<<"\t\t"<<process[alloc[i]]<<"\t\t"<<fragment[i]<<endl;
        }
        else{
            cout<<block[i]<<"\t\t"<<"---------------------------------------------"<<endl;
        }
    }

    
    return 0;
}