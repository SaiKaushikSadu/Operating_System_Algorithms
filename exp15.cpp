#include<bits/stdc++.h>
using namespace std;

struct filetable{
    int nb;
    int sb;
    char name[20];
}ft[30];

int main(){

    //Contigous File Allocation
    char target[20];
    int n;
    cout<<"Enter the no of files"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the file name"<<endl;
        cin>>ft[i].name;
        cout<<"Enter the no of blocks"<<endl;
        cin>>ft[i].nb;
        cout<<"Enter the no of starting block"<<endl;
        cin>>ft[i].sb;
    }

    cout<<"Enter the file name to be searched"<<endl;
    cin>>target;

    int i;
    for(i=0;i<n;i++){
        if(strcmp(target,ft[i].name)==0){
            break;
        }
    }

    if(i==n){
        cout<<"Page not found"<<endl;
    }
    else{
        cout<<"File name\tNo of Blocks\tBlock nos"<<endl;
        cout<<ft[i].name<<"\t\t"<<ft[i].nb<<"\t\t";
        for(int j=0;j<ft[i].nb;j++){
            cout<<ft[i].sb+j<<" ";
        }
        cout<<endl;
    }

    return 0;
}