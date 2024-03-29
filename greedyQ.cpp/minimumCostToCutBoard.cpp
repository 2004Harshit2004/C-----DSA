#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>    

using namespace std;

// Time complexity = O(nlog(n)+mlog(m))

bool cmp(int a,int b){
    return a>b;
}

int miniCost(int m,int n,vector<int> vertical,vector<int> horizontal){
    sort(vertical.begin(),vertical.end(),cmp);
    sort(horizontal.begin(),horizontal.end(),cmp);
    int v=1,h=1;
    int cost=0;
    int i=0,j=0;
    while(i<m && j<n){
        if(vertical[i]>horizontal[j]){
            cost+=vertical[i]*h;
            v++;++i;
        }else{
            cost+=horizontal[j]*v;
            h++;++j;
        }
    }
    while(i<m){
        cost+=vertical[i]*h;
        v++;++i;
    }
    while (j<n){
        cost+=horizontal[j]*v;
        h++;++j;    
    }
    
    return cost;
}

int main(){
    vector<int> x={2,1,3,1,4};
    vector<int>y={4,1,2};
    int m=6;
    int n=4;
    cout<<miniCost(6,4,x,y);
}