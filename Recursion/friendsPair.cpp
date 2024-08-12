// Given n friends , each one can remain single or can be paired up with some other friend .
// Each friend can be paired only once . Find out the total number of ways in  which friends
// can remain single or can be paired up .

#include<iostream>

using namespace std;

int count(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    return count(n-1) + (n-1) * count(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<count(n);
}