#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //MVT
    int mem;
    cout<<"Enter the total memory size"<<endl;
    cin>>mem;

    int fragment=mem;

    int z;
    int i=0;
    int process[100];
    do{

        cout<<"Enter the Process Size: ";
        cin>>process[i];

        if(fragment>=process[i]){
            fragment-=process[i];
            i++;
        }
        else{
            cout<<"Memory is Full"<<endl;
            break;
        }

        cout<<"Enter 1 to continue and 0 to exit"<<endl;
        cin>>z;
    }while(z==1);

    cout<<"Process\tAllocated mem"<<endl;
    for(int j=0;j<i;j++){
        cout<<j<<"\t"<<process[j]<<endl;
    }

    cout<<"Total memory allocated= "<<mem-fragment<<endl;
    cout<<"Fragment= "<<fragment<<endl;;
    
    return 0;
}