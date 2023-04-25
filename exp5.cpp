#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //First fit

    //Blocks
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
    for(int i=0;i<np;i++){
        for(int j=0;j<nb;j++){
            if(flag[j]==0 && block[j]>=process[i]){
                alloc[j]=i;
                flag[j]=1;
                fragment[j]=block[j]-process[i];
                break;
            }
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