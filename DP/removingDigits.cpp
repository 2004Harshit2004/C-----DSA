#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> digits(int n){
    vector<int> hg;
    while(n>0){
        if(n%10!=0) hg.push_back(n%10);
        n=n/10;
    }
    return hg;
}

vector<int> dp;

int f(int n){
    if(n==0) return 0;
    if(n/10==0) return 1;
    if(dp[n]!=-1) return dp[n];
    vector<int> hg = digits(n);
    int res=INT_MAX;
    for(int i=0;i<hg.size();++i){
      res=min(res,f(n-hg[i]));  
    }
    return dp[n]=1+res;
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n+5,-1);
    cout<<f(n);

}