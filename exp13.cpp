#include <bits/stdc++.h>
using namespace std;

int formula(int a){
    return ceil(log2(a));
}

int to_decimal(string s){
    int dec=0;
    int p=0;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='1'){
            dec+=pow(2,p);
        }
        p++;
    }
    return dec;
}

void page_table(int len){
    map<int,pair<int,bool>> pg_table;

    int n;
    cout<<"Enter the no of entries"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int pno;
        int fno;
        int valid;
        cout<<"Enter the page no"<<endl;
        cin>>pno;
        cout<<"Enter the frame no"<<endl;
        cin>>fno;
        cout<<"Enter 1/0 based on whether the page is present in PT or not"<<endl;
        cin>>valid;

        pg_table[pno]={fno,valid};
    }

    string logical_add;
    cout<<"Enter the logical address in binary"<<endl;
    cin>>logical_add;

    int temp=to_decimal(logical_add.substr(0,len));
    auto it=pg_table.find(temp);

    if(it!=pg_table.end()){
        if(it->second.second==1){
            cout<<"Page Hit"<<endl;
        }
        else{
            cout<<"Page Fault"<<endl;
        }
    }   
    else{
        cout<<"Given Page is not in use";
    }

}

int main(){

    // Paging Technique
    
    int pro_size;
    cout << "Enter the process size in KB " << endl;
    cin >> pro_size;

    int pg_size;
    cout << "Enter the page size in BYTES " << endl;
    cin >> pg_size;

    int mem_size;
    cout << "Enter the phy memory size in MB " << endl;
    cin >> mem_size;

    int total_frames = ceil((mem_size * pow(2, 20)) / pg_size);
    cout << "Total no of frames= " << total_frames<<endl;

    int total_entries_pg = ceil((pro_size * pow(2, 10)) / pg_size);
    cout << "Total no of entries in page table= " << total_entries_pg<<endl;

    cout << "No of bits in physical address " << formula(mem_size * pow(2, 20))<<endl;

    int pg_bits = formula(pro_size * pow(2, 10)) - formula(pg_size);

    cout << "No of bits in logical address is " << formula(pro_size * pow(2, 10)) << " out of which " << pg_bits << " bits represent page no and " << formula(pg_size) << " bits represent offset" << endl;

    page_table(pg_bits);

    return 0;
}
