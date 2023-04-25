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

int main(){
    
    //LRU Page Replacement
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
    int occupied=0;
    int q[p];
    int dis[p];

    cout<<"Ref\tFrame1\tFrame2\tFrame3"<<endl;
    for(int i=0;i<p;i++){
        cout<<ref[i]<<'\t';

        if(checkHit(ref[i],occupied,q)){
            print(q,occupied);
        }
        else if(occupied<f){
            q[occupied]=ref[i];
            fault++;
            occupied++;
            print(q,occupied);
        }
        else{
            int max=INT_MIN;
            int index;

            for(int j=0;j<f;j++){
                dis[j]=0;
                for(int k=i-1;k>=0;k--){
                    ++dis[j];
                    if(q[j]==ref[k]){
                        break;
                    }
                }
                if(dis[j]>max){
                    max=dis[j];
                    index=j;
                }
            }

            q[index]=ref[i];
            fault++;
            print(q,occupied);
        }
        // cout<<endl;
    }
    
    int hits=p-fault;
    cout<<"No. of Page Hits= "<<hits<<endl;
    cout<<"Hit Ratio= "<<hits<<"/"<<p<<endl;
    cout<<"No. of Page Faults= "<<fault<<endl;
    cout<<"Miss Ratio= "<<fault<<"/"<<p<<endl;

    return 0;
}