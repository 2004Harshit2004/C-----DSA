#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int>q){
    while(q.size()!=0){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reverseK(int k,queue<int>&q){
    stack<int>s;
    for(int i=1;i<=k;++i){
        s.push(q.front());
        q.pop();
    }

    for(int i=0;i<k;++i){
        q.push(s.top());
        s.pop();
    }

    int n=q.size();
    for(int i=0;i<n-k;++i){
        q.push(q.front());
        q.pop();
    }
}
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    display(q);
    reverseK(897,q);
    
    display(q);
}