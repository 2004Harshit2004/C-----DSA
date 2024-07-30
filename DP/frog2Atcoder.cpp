#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> v;
vector<int> dp;
int k;

int f(int i){
    if(i==v.size()-1) return 0;
    if(dp[i]!=-1) return dp[i]; 
    int ans=INT_MAX;
    for(int j=1;j<=k && i+j<v.size();++j){
        ans=min(ans,abs(v[i]-v[i+j])+f(i+j));
    }
    dp[i]=ans;
    return ans;
}

int main(){
    int n;
    cin>>n>>k;
    v.clear();
    v.resize(n);
    dp.resize(n,-1);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    cout<<f(0);
}