#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int f(int n){
    if(n==0 || n==1) return n;
    if(v[n]!=-1) return v[n];
    return v[n]=f(n-1)+f(n-2);
}

int main(){
    int n;
    cin>>n;
    v.clear();
    v.resize(n+1,-1);
    cout<<f(n);

}