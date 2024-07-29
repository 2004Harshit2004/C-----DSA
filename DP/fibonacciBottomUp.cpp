#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int f(int n){
    v[0]=0;
    v[1]=1;
    for(int i=2;i<=n;++i){
        v[i]=v[i-1]+v[i-2];
    }
    return v[n];
}

int main(){
    int n;
    cin>>n;
    v.clear();
    v.resize(n+1,-1);
    cout<<f(n);

}