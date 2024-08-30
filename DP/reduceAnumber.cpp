// Given a number n , you can perform these operation to reduce number to 1 any number of times
// n = n-1
// if n is divisible by 2 -> n = n/2
// if n is divisible by 3 -> n = n/3
// find minimum number of operation to reduce number to 1

#include<iostream>
#include<climits>
#include <algorithm>
#include<vector>
using namespace std;
#define inf INT_MAX

int f(int n){
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    int a,b=INT_MAX,c=INT_MAX;
    a=f(n-1);
    if(n%2==0) b=f(n/2);
    if(n%3==0) c=f(n/3);
    return 1+min(a,min(b,c));
    
}

vector<int> dp;
int ftd(int n){
    // TC=O(n) SC=O(n)
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    return 1+min({dp[n-1]=ftd(n-1),n%2==0?dp[n/2]=ftd(n/2):inf,n%3==0?dp[n/3]=ftd(n/3):inf});
}

int fbu(int n){
    // TC=O(n) SC=O(n)
    dp[1]=0;
    dp[2]=dp[3]=1;
    for(int i=4;i<=n;++i){
        dp[i]=1+min({dp[i-1],i%2==0?dp[i/2]:inf,i%3==0?dp[i/3]:inf});
    }
    return dp[n];
}

int main(){
    int m;
    cin>>m;
    dp.resize(m+1,-1);
    cout<<ftd(m)<<" "<<fbu(m);
}