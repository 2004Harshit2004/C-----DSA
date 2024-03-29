#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void display(vector<int> v){
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void downheapify(int idx,vector<int> &v,int n){
    while(1){
        int mxi=idx;
        int lci=2*idx+1;
        int rci=2*idx+2;
        if(lci>=n) return;
        if(v[lci]>v[mxi]) mxi=lci;
        if(rci<n && v[rci]>v[mxi]) mxi=rci;
        if(mxi==idx) return;
        else{
            swap(v[mxi],v[idx]);
            idx=mxi;
        }
    }
}

int main(){
    vector<int> v={2,11,3,5,4,9,8,10,7};
    display(v);
    int n=v.size();
    for(int i=n/2;i>=0;--i){
        downheapify(i,v,n);
    }
    // priority_queue<int> pq(v.begin(),v.end());
    display(v);
    int i=n-1;
    while(i!=0){
        swap(v[0],v[i]);
        downheapify(0,v,i);
        --i;
    }
    display(v);
}