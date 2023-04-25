#include<bits/stdc++.h>
using namespace std;

int checkHit(int curr, int occupied, int q[]){
    for(int i=0;i<occupied;i++){
        if(curr==q[i]){
            return 1;
        }
    }
    return 0;
}

void print(int q[], int occupied){
    for(int i=0;i<occupied;i++){
        cout<<q[i]<<"\t";
    }
    cout<<endl;
}

int predict(int ref[],int q[],int p,int index,int occupied){
    int result=-1;
    int fartest=index;
    for(int i=0;i<occupied;i++){
        int j;
        for(j=index;j<p;j++){
            if(q[i]==ref[j]){
                if(j>fartest){
                    fartest=j;
                    result=i;
                }
                break;
            }
        }

        if(j==p){
            return i;
        }
    }
    return (result==-1)?0:result;
}

int main(){
    
    //Optimal Page Replacement
    int p;
    int f;
    cout<<"Enter the no of pages"<<endl;
    cin>>p;
    cout<<"Enter the no of frames"<<endl;
    cin>>f;
    int ref[p];
    cout<<"Enter the pages"<<endl;
    for(int i=0;i<p;i++){
        cin>>ref[i];
    }

    int occupied=0;
    int q[p];

    int hits=0;
    cout<<"Ref\tFrame1\tFrame2\tFrame3"<<endl;
    for(int i=0;i<p;i++){
        cout<<ref[i]<<"\t";

        if(checkHit(ref[i],occupied,q)){
            hits++;
            print(q,occupied);
        }
        else if(occupied<f){
            q[occupied]=ref[i];
            occupied++;
            print(q,occupied);
        }
        else{
            int pos=predict(ref,q,p,i+1,occupied);
            q[pos]=ref[i];
            print(q,occupied);
        }

    }
    
    int fault=p-hits;
    cout<<"No. of Page Hits= "<<hits<<endl;
    cout<<"Hit Ratio= "<<hits<<"/"<<p<<endl;
    cout<<"No. of Page Faults= "<<fault<<endl;
    cout<<"Miss Ratio= "<<fault<<"/"<<p<<endl;
    
    return 0;
}