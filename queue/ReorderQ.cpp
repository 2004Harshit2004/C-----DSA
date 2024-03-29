#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void display(queue<int>q){
    while(q.size()!=0){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    display(q);
    int n=q.size();
    stack<int>st;
    for(int i=1;i<=n/2;++i){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    
    for(int i=1;i<=n/2;++i){
        st.push(q.front());
        q.pop();
    }
    
    for(int i=1;i<=n/2;++i){
        q.push(st.top());
        q.push(q.front());
        q.pop();
        st.pop();
    }
     display(q);
}