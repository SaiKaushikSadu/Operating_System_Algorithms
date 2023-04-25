#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //FIFO Page replacement
    int p;
    int f;

    cout<<"Enter the no of pages"<<endl;
    cin>>p;
    cout<<"Enter the no of frames"<<endl;
    cin>>f;

    //Refrence string
    int ref[p];
    cout<<"Enter the elements of ref string"<<endl;
    for(int i=0;i<p;i++){
        cin>>ref[i];
    }

    int fault=0;
    int s=0;

    int temp[f];//storing the pages in the frames(each iteration)
    for(int i=0;i<f;i++){
        temp[i]=-1;
    }

    cout<<"Ref\tFrame1\tFrame2\tFrame3"<<endl;

    for(int i=0;i<p;i++){
        s=0;
        for(int j=0;j<f;j++){
            if(ref[i]==temp[j]){
                s++;
                fault--;
            }
        }
        fault++;

        if(fault<=f && s==0){
            temp[i]=ref[i];
        }
        else if(s==0){
            temp[(fault-1)%f]=ref[i];
        }

        cout<<endl;

        cout<<ref[i]<<"\t";

        for(int j=0;j<f;j++){
            if(temp[j]!=-1){
                cout<<temp[j]<<"\t";
            }
            else{
                cout<<"-\t";
            }
        }
    }

    cout<<endl;

    int hits=p-fault;
    cout<<"No. of Page Hits= "<<hits<<endl;
    cout<<"Hit Ratio= "<<hits<<"/"<<p<<endl;
    cout<<"No. of Page Faults= "<<fault<<endl;
    cout<<"Miss Ratio= "<<fault<<"/"<<p<<endl;
    
    return 0;
}

