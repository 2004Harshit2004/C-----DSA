//  Given a number n , count the number of binary strings of length n 
//  without consecutive one

#include<iostream>

using namespace std;

// Forming a relation of fibonacci series
int count(int n){
    if(n==1) return 2;
    if(n==2) return 3;
    return count(n-1) + count(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<count(n);
}