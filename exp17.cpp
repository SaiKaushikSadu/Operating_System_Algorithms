#include<bits/stdc++.h>
using namespace std;
int main(){
    
    //Banker's Algorithm

    int n;//process
    int m;//resources

    cout<<"Enter the no of process"<<endl;
    cin>>n;

    cout<<"Enter the no of resources"<<endl;
    cin>>m;

    int alloc[n][m];
    int maxa[n][m];
    int total_res[m];
    int avail[m];
    int need[n][m];

    //Allocation
    cout<<"Enter the allocation matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>alloc[i][j];
        }
    }
    
    //Maximum allocation
    cout<<"Enter the max allocation matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maxa[i][j];
        }
    }

    //Total instance of each resource
    cout<<"Enter the total no of resources"<<endl;
    for(int i=0;i<m;i++){
        cin>>total_res[i];
    }

    //Default
    for(int i=0;i<m;i++){
            avail[i]=0;
    }

    //Finding available resources
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            avail[j]+=alloc[i][j];
            // cout<<alloc[j][i]<<" ";
        }
        // cout<<endl;
    }
    for(int i=0;i<m;i++){
        avail[i]=total_res[i]-avail[i];
    }

    cout<<"The available resources are :"<<endl;
    for(int i=0;i<m;i++){
            cout<<avail[i];
    }
    cout<<endl;

    //Directly input available resources
    // cout<<"Enter avail res"<<endl;
    // for(int i=0;i<m;i++){
    //     cin>>avail[i];
    // }

    int f[n];
    int ans[n];
    int index=0;

    //default
    for(int k=0;k<n;k++){
        f[k]=0;
    }

    //calc need matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=maxa[i][j]-alloc[i][j];
        }
    }

    //logic
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            if(f[i]==0){
                int flag=0;
                for(int j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[index++]=i;
                    for(int y=0;y<m;y++){
                        avail[y]+=alloc[i][y];
                    }
                    f[i]=1;
                }
            }
        }
    }

    int flag=1;

    for(int i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
            cout<<"The system is not safe"<<endl;
            break;
        }
    }

    if(flag==1){
        cout<<"The following safe sequence is :"<<endl;
        for(int i=0;i<n-1;i++){
            cout<<"P["<<ans[i]<<"] -> ";
        }
        cout<<"P["<<ans[n-1]<<"] "<<endl;
    }

    return 0;
}
