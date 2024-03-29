#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int miniProduct(vector<int> v){
    int pe=0,ne=0,z=0;
    int mnp=INT_MAX;
    int mul=1;
    int mxn=INT_MIN;
    for(int i=0;i<v.size();++i){
        if(v[i]>0){
            mnp=min(mnp,v[i]);
            ++pe;
        }
        else if(v[i]<0){
            mxn=max(mxn,v[i]);
            ++ne;
        }
        else ++z;
        if(v[i]!=0) mul*=v[i];
    }
    if(ne==0){
        if(z==0){
            return mnp;
        }
        else return 0;
    }
    else{
        if(ne%2==0){
            return mul/mxn;
        }
        else{
            return mul;
        }
    }

}

int main(){
    vector<int> v={-1,0,-2,};
    cout<<miniProduct(v);
}